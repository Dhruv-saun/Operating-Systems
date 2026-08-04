# Child Exits with Status 10

## Problem Statement

Write a C++ program in which the child process exits with status code **10**, and the parent process retrieves and displays the child's exit status using the `wait()` system call.

## Objective

- Understand process termination using `exit()`.
- Learn how a parent process waits for a child process.
- Retrieve the child's exit status using `wait()` and `WEXITSTATUS()`.

## System Calls and Macros Used

- `fork()` – Creates a new child process.
- `wait()` – Waits for the child process to terminate.
- `exit()` – Terminates the child process with a specified exit status.
- `WIFEXITED(status)` – Checks whether the child terminated normally.
- `WEXITSTATUS(status)` – Retrieves the child's exit status.

## Header Files

```cpp
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
```

## Algorithm

1. Create a child process using `fork()`.
2. Check whether the child process is created successfully.
3. In the child process:
   - Display a message.
   - Terminate using `exit(10)`.
4. In the parent process:
   - Wait for the child process using `wait()`.
   - Check whether the child terminated normally using `WIFEXITED()`.
   - Display the exit status using `WEXITSTATUS()`.
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
Child Process
Parent Process
Child exited with status: 10
```

> **Note:** The exit status returned by `exit()` should be in the range **0–255**. The parent can retrieve this value only after the child process has terminated.

## Concepts Covered

- Process Creation
- Process Termination
- Parent and Child Processes
- Process Synchronization
- Exit Status
- `fork()`
- `wait()`
- `exit()`
- `WIFEXITED()`
- `WEXITSTATUS()`

## Files

```
child-exit-status-10/
├── solution.cpp
└── README.md
```

## Author

**Dhruv Saun**