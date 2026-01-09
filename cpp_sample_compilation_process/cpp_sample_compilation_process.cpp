#include <iostream>

/*
* When compiling this file, the following steps occur:
* 1. Preprocessing: The preprocessor handles directives like #include and #define.
* 2. Compilation: The preprocessed code is translated into assembly language specific to the target architecture.
* 3. Assembly: The assembly code is converted into machine code, resulting in object files (.o or .obj).
* 4. Linking: The linker combines object files and libraries to create the final executable.
* This process can be influenced by various compiler flags and options.
* 
* To view the intermediate stages, you can use compiler flags such as:
* /P    - Preprocessing only
* /Fa   - Compilation to assembly
* /c    - Compilation to object code (machine code)
*/

int main()
{
    std::cout << "Hello World!\n";
}