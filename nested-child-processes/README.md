# Nested Child Processes: Factorial, Fibonacci and Sum

## Problem Statement

Write a C++ program in which:

- The **innermost child process** prints the factorial of `n`.
- The **middle child process** prints the Fibonacci series up to `n` terms.
- The **main parent process** prints the sum of all numbers from `1` to `n`.

The program should use nested `fork()` system calls and synchronize processes using `wait()`.

## Objective

- Understand nested process creation.
- Learn parent-child hierarchy in Linux.
- Perform different tasks in different processes.
- Synchronize process execution using `wait()`.

## System Calls Used

- `fork()`
- `wait()`

## Header Files

```cpp
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
```

## Algorithm

1. Read the value of `n`.
2. Create the first child process.
3. Inside the first child, create another child process.
4. The innermost child calculates and prints the factorial.
5. The middle child waits for the innermost child and prints the Fibonacci series.
6. The parent waits for the middle child and prints the sum of numbers from `1` to `n`.
7. End the program.

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

Innermost Child Process (Factorial): 120

Middle Child Process (Fibonacci):
0 1 1 2 3

Parent Process (Sum): 15
```

> **Note:** The `wait()` system call ensures the execution order: innermost child → middle child → parent.

## Concepts Covered

- Nested Processes
- Parent and Child Processes
- Process Hierarchy
- Process Synchronization
- `fork()`
- `wait()`
- Factorial
- Fibonacci
- Summation

## Files

```
nested-child-processes/
├── solution.cpp
└── README.md
```

## Author

**Dhruv Saun**