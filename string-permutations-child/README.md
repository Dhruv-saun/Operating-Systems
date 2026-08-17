# String Permutations in Child Process

## Problem Statement

Write a C++ program to read a string from the user within the child process and print all possible permutations of the characters of the given string.

## Objective

- Understand process creation using `fork()`.
- Perform string operations inside the child process.
- Generate all permutations of a string using recursion.
- Understand the concept of backtracking.
- Synchronize the parent and child processes using `wait()`.

## System Calls Used

- `fork()` – Creates a child process.
- `wait()` – Makes the parent process wait for the child process to complete.

## Function Used

### `permutations(string str, int left, int right)`

Generates all possible permutations of the given string using recursion and backtracking.

The function swaps characters at different positions, recursively generates permutations, and then restores the original arrangement through backtracking.

## Algorithm

1. Create a child process using `fork()`.
2. In the child process:
   - Read a string from the user.
   - Call the `permutations()` function.
   - Generate and print all permutations.
3. In the parent process:
   - Wait for the child process using `wait()`.
   - Display a completion message.
4. End the program.

## Compilation

```bash
g++ solution.cpp -o solution
```

## Execution

```bash
./solution
```

## Sample Output

For the input `ABC`:

```text
Child Process
Enter a string: ABC

Permutations of ABC are:
ABC
ACB
BAC
BCA
CBA
CAB

Parent Process completed.
```

## Concepts Covered

- Process Creation
- Parent and Child Processes
- String Manipulation
- Recursion
- Backtracking
- Process Synchronization
- `fork()`
- `wait()`

## Files

```text
string-permutations-child/
├── solution.cpp
└── README.md
```

## Author

**Dhruv Saun**