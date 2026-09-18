# File Handling Using Pipe and Fork

## Aim

Create a file in the parent process, write student details into it, and read and display the file contents in the child process. The file name is passed from the parent to the child using a pipe.

## Concepts Used

- `fork()` to create a child process
- `pipe()` for inter-process communication
- File writing using `ofstream`
- File reading using `ifstream`
- `wait()` for process synchronization

## Compilation

This program uses POSIX functions, so run it in Linux or WSL.

````bash
g++ solution.cpp -o solution

Input
The program asks for:

File name
Name
University roll number
Class roll number
Working
The program creates a pipe.
The parent process creates the file and writes the student details.
The parent sends the file name to the child through the pipe.
The child receives the file name.
The child opens and reads the file.
The file contents are displayed on the screen.
Sample Output
Enter file name: input.txt
Enter your name: Dhruv Saun
Enter university roll number: 2418458
Enter class roll number:  двадцать

Content of the file:
Name: Dhruv Saun
University Roll No: 2418458
Class Roll No:  двадцать