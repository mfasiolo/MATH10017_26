//I am a comment
/*
    I am a multi-line 
    comment
*/

//The code below is a preprocessing command.
//It will be executed before compilation
#include <stdio.h>

//The code below is a function, contains a list of instructions
// to be compiled and run on the CPU. 
int main()
{
    //below are statements, they will be executed sequentially.
    printf("My name is Matteo Fasiolo. \n");
    printf("I am from Italy. \n");
    printf("My student ID is mf12345. \n");
    printf("My favourite food is pasta carbonara. \n");

    //the following statement returns a value from this function.
    //Here, it returns "0", means all OK with your program. 
    //If needded, you can return a non-zero value which means something is wrong. 
    return 0;
}

/*
To compile, press ctrl+' to bring out the command line. 

Type ine the command line gcc THIS_FILE_NAME -o EXECUTABLE_FILE_NAME 
(on Windows, the file name must end with .exe)
Press enter. 

To run, 
Type in the command line ./EXECUTABLE_FILE_NAME 
press enter. 

*/
