# Even or Odd in Child and Factorial in Parent

## Problem Statement

Write a C++ program in which the child process checks whether a given number is even or odd, while the parent process calculates the factorial of the number.

The program should also print the Process ID (PID) and Parent Process ID (PPID).

## Objective

- Understand process creation using `fork()`.
- Perform different operations in the parent and child processes.
- Retrieve process identifiers using `getpid()` and `getppid()`.
- Synchronize the parent and child processes using `wait()`.

## System Calls Used

- `fork()` – Creates a child process.
- `wait()` – Makes the parent wait for the child process.
- `getpid()` – Returns the Process ID of the current process.
- `getppid()` – Returns the Parent Process ID.

## Algorithm

1. Read an integer `n`.
2. Create a child process using `fork()`.
3. In the child process:
   - Print its PID.
   - Print its parent's PID.
   - Check whether `n` is even or odd.
4. In the parent process:
   - Wait for the child using `wait()`.
   - Print the parent's PID.
   - Print the child's PID.
   - Calculate and print the factorial of `n`.
5. End the program.

## Compilation

```bash
g++ solution.cpp -o solution