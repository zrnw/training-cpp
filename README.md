## **This project is focused on C++ training and the creation of a dropper with the following steps: **

### **Steps:**
:**Shellcode Embedding::** The shellcode (in this example, it launches calc.exe) is embedded in the application’s resources (inside the .rsrc section).

:**Shellcode Encryption::** The shellcode is encrypted using XOR with a simple key to hide its content.

:**Runtime Decryption::** At runtime, the shellcode is extracted and decrypted in memory.

:**Shellcode Injection::** The decrypted shellcode is injected into a target process (e.g., notepad.exe) by allocating memory in the target process, writing the shellcode there, and creating a remote thread to execute it.

:**Console Window Hiding::** The use of WinMain hides the console window during execution.

