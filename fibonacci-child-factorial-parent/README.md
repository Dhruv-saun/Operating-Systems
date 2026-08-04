# Fibonacci Series in Child Process and Factorial in Parent Process

## Problem Statement

Write a C++ program in which the **child process prints the Fibonacci series up to _n_ terms** and the **parent process prints the factorial of _n_** using the `fork()` system call.

## Objective

- Understand process creation using `fork()`.
- Perform different tasks in parent and child processes.
- Synchronize execution using `wait()`.

## System Calls Used

- `fork()` – Creates a child process.
- `wait()` – Makes the parent process wait for the child process to complete.

## Header Files

```cpp
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
```

## Algorithm

1. Read the value of `n`.
2. Create a child process using `fork()`.
3. If the process is the child:
   - Print the Fibonacci series up to `n` terms.
4. Otherwise (parent process):
   - Wait for the child process to finish.
   - Calculate the factorial of `n`.
   - Display the factorial.
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
Enter a number: 5

Child Process (Fibonacci Series):
0 1 1 2 3

Parent Process (Factorial):
120
```

> **Note:** Since the parent process uses `wait()`, the Fibonacci series is displayed before the factorial.

## Concepts Covered

- Process Creation
- Parent and Child Processes
- Process Synchronization
- Fibonacci Series
- Factorial
- `fork()`
- `wait()`

## Files

```
fibonacci-child-factorial-parent/
├── solution.cpp
└── README.md
```

## Author

**Dhruv Saun**