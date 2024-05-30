Introduction project for the c-language and make
================================================
This is my first complete project in the coding language C. It is a simple program that allows users to perform the mathematic add operation with two natural numbers.  

Note: When entering the numbers in the terminal, typing decimal numbers will not result in an error. Instead, the decimal number will be rounded down to the next smallest integer value.  

## Content of the add project
* add.c contains the main-file which handels user arguments and passes them down to the helper and main project functionalities.
* core.h header file. Declaration of the project functions
* core.c implements the functions declared in the header.
* core_test.c contains the projects unit-tests
* Doxyfile is a script file that is used to autogenerate documentation for the project with Doxygen.
* makefile is a script file that simplifies compilation, deletion and documentation generation of the project files.

## Instructions how to use the add project

1.) Download the project folder.  
2.) Navigate with the change directory (cd) command into the folder where the project is stored. Your current path should end with .../add$  
3.) type "make" into the terminal to complain the executable file.  
4.) type "./add number 1 number 2" number 1 and 2 being integer values.  
5.) type "make clean" to delete the compiled files again "make doxygen" creates an automated PDF file that serves as project documentation.  

