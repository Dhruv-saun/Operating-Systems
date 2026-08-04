# Parent Prints Even Numbers and Child Prints Odd Numbers

## Problem Statement

Write a C++ program in which the parent process prints the even numbers from **1 to 20** and the child process prints the odd numbers using the `fork()` system call.

## Objective

- Understand process creation using `fork()`.
- Differentiate between parent and child processes.
- Demonstrate concurrent execution of processes.
- Use `wait()` to synchronize the parent process with the child process.

## System Calls Used

- `fork()` - Creates a new child process.
- `wait()` - Makes the parent process wait until the child process finishes execution.

## Header Files

```cpp
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
```

## Algorithm

1. Create a child process using `fork()`.
2. Check whether the process creation was successful.
3. If the current process is the child:
   - Print all odd numbers from 1 to 20.
4. Otherwise (parent process):
   - Wait for the child process to complete using `wait()`.
   - Print all even numbers from 2 to 20.
5. End the program.

## Compilation

```bash
g++ solution.cpp -o solution
```

## Execution

```bash
./solution
```

## Sample Output

```text
Child Process (Odd Numbers):
1 3 5 7 9 11 13 15 17 19

Parent Process (Even Numbers):
2 4 6 8 10 12 14 16 18 20
```

> **Note:** The exact output order may vary if `wait()` is removed. In this program, `wait()` ensures that the child process finishes before the parent starts printing.

## Concepts Covered

- Process Creation
- Parent Process
- Child Process
- Process Synchronization
- fork()
- wait()

## Author

Dhruv Saun