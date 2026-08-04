# Create Three Child Processes

## Problem Statement

Write a C++ program to create **three child processes** using the `fork()` system call. Each child process should print its **Child Number**, **Process ID (PID)**, and **Parent Process ID (PPID)**.

## Objective

- Understand the creation of multiple child processes.
- Learn how `fork()` behaves inside a loop.
- Display the process identifiers of parent and child processes.
- Observe the relationship between parent and child processes.

## System Calls Used

- `fork()` – Creates a new child process.
- `wait()` – Makes the parent process wait for all child processes to complete.
- `getpid()` – Returns the Process ID (PID) of the calling process.
- `getppid()` – Returns the Parent Process ID (PPID) of the calling process.

## Header Files

```cpp
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
```

## Algorithm

1. Start the program.
2. Execute a loop three times.
3. In each iteration:
   - Create a child process using `fork()`.
   - If the process is the child:
     - Print the child number.
     - Print its PID.
     - Print its PPID.
     - Exit the child process.
4. The parent process waits for all three child processes using `wait()`.
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
Child 1
PID: 3251
PPID: 3248

Child 2
PID: 3252
PPID: 3248

Child 3
PID: 3253
PPID: 3248
```

> **Note:** The PID and PPID values will be different on every execution.

## Concepts Covered

- Process Creation
- Multiple Child Processes
- Parent and Child Relationship
- Process Identification
- Process Synchronization
- `fork()`
- `wait()`
- `getpid()`
- `getppid()`

## Files

```
create-three-child-processes/
├── solution.cpp
└── README.md
```

## Author

**Dhruv Saun**