# Operating Systems Lab Programs

This repository contains my **Operating Systems lab programs** implemented in **C++**. The programs demonstrate fundamental concepts of process creation, process synchronization, process IDs, process termination, and basic problem-solving using Linux system calls.

## Environment

- **Language:** C++
- **Operating System:** Linux / Ubuntu
- **Execution Environment:** WSL (Windows Subsystem for Linux)
- **Compiler:** g++
- **Version Control:** Git & GitHub

> The programs use Linux-specific system calls such as `fork()` and `wait()`, so they are intended to be compiled and executed in a Linux environment such as Ubuntu/WSL.

---

## Repository Structure

Each program is stored in a separate folder.

```text
Operating-Systems/
│
├── README.md
│
├── parent-even-child-odd/
│   ├── solution.cpp
│   └── README.md
│
├── create-three-child-processes/
│   ├── solution.cpp
│   └── README.md
│
├── child-exit-status-10/
│   ├── solution.cpp
│   └── README.md
│
├── fibonacci-child-factorial-parent/
│   ├── solution.cpp
│   └── README.md
│
├── nested-child-processes/
│   ├── solution.cpp
│   └── README.md
│
├── even-odd-child-factorial-parent/
│   ├── solution.cpp
│   └── README.md
│
└── fibonacci-child-armstrong-parent/
    ├── solution.cpp
    └── README.md
```

Each program folder contains:

- `solution.cpp` — C++ implementation of the program.
- `README.md` — Problem statement, algorithm, concepts, compilation instructions, and sample output.

---

# Programs

| No. | Program | Folder |
|-----|---------|--------|
| 1 | Parent prints even numbers and child prints odd numbers | [parent-even-child-odd](./parent-even-child-odd/) |
| 2 | Create three child processes | [create-three-child-processes](./create-three-child-processes/) |
| 3 | Child exits with status 10 and parent reads the status | [child-exit-status-10](./child-exit-status-10/) |
| 4 | Fibonacci series in child and factorial in parent | [fibonacci-child-factorial-parent](./fibonacci-child-factorial-parent/) |
| 5 | Nested child processes for factorial, Fibonacci and sum | [nested-child-processes](./nested-child-processes/) |
| 6 | Even/Odd in child and factorial in parent | [even-odd-child-factorial-parent](./even-odd-child-factorial-parent/) |
| 7 | Fibonacci in child and Armstrong numbers in parent | [fibonacci-child-armstrong-parent](./fibonacci-child-armstrong-parent/) |

---

# Concepts Covered

The programs in this repository cover the following Operating Systems concepts:

### Process Management

- Process creation
- Parent process
- Child process
- Multiple child processes
- Nested processes
- Process hierarchy

### Process Identification

- Process ID (PID)
- Parent Process ID (PPID)
- `getpid()`
- `getppid()`

### Process Synchronization

- `wait()`
- Parent-child synchronization
- Process execution order

### Process Termination

- `exit()`
- Child process exit status
- `WIFEXITED()`
- `WEXITSTATUS()`

### Linux System Calls

- `fork()`
- `wait()`
- `getpid()`
- `getppid()`

### Programming Concepts

- Fibonacci series
- Factorial
- Even and odd numbers
- Armstrong numbers
- Functions
- Loops
- Conditional statements

---

# Compilation and Execution

Since these programs use Linux-specific system calls, they should be compiled and executed in **Linux/Ubuntu or WSL**.

## Compile

Navigate to the required program folder:

```bash
cd parent-even-child-odd
```

Compile the program:

```bash
g++ solution.cpp -o solution
```

## Run

```bash
./solution
```

The same commands can be used for all program folders.

---

# Git Workflow

The repository is maintained using Git and GitHub.

After completing a program:

```bash
git status
```

Stage the changes:

```bash
git add .
```

Commit the program:

```bash
git commit -m "Add <program-name> program"
```

Push the changes:

```bash
git push origin main
```

Each Operating Systems program is maintained as a separate commit to keep the Git history organized.

---

# Author

**Dhruv Saun**

B.Tech CSE  
Graphic Era Hill University

---

## Repository Goal

This repository is being maintained as a structured collection of Operating Systems programs and lab assignments, with each problem documented separately for easy reference and future revision.