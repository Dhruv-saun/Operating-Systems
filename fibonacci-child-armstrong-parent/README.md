# Fibonacci in Child and Armstrong Numbers in Parent

## Problem Statement

Write a C++ program to call a Fibonacci function in the child process and print the Fibonacci series up to `n`. In the parent process, call an Armstrong function and print all Armstrong numbers up to `n`.

## Objective

- Understand process creation using `fork()`.
- Call different functions in parent and child processes.
- Generate the Fibonacci series using a function.
- Identify Armstrong numbers within a given range.
- Synchronize the parent and child processes using `wait()`.

## System Calls Used

- `fork()` – Creates a child process.
- `wait()` – Makes the parent process wait for the child process to complete.

## Functions Used

### `fibonacci(int n)`

Generates and prints the first `n` terms of the Fibonacci series.

### `armstrong(int n, int digits)`

Checks whether a number is an Armstrong number by calculating the sum of its digits raised to the power of the number of digits.

## Algorithm

1. Create a child process using `fork()`.
2. In the child process:
   - Read the value of `n`.
   - Call the `fibonacci()` function.
   - Print the Fibonacci series up to `n` terms.
3. In the parent process:
   - Wait for the child process using `wait()`.
   - Read the upper limit `n`.
   - Check every number from `0` to `n`.
   - Call the `armstrong()` function for each number.
   - Print the Armstrong numbers.
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

```text
Enter n for Fibonacci series: 7
Fibonacci Series: 0    1    1    2    3    5    8

Enter n for Armstrong number range: 500
Armstrong Numbers: 0    1    2    3    4    5    6    7    8    9    153    370    371    407
```

> **Note:** The PID and execution order can vary depending on process scheduling. The `wait()` call ensures that the parent performs its task after the child process finishes.

## Concepts Covered

- Process Creation
- Parent and Child Processes
- Process Synchronization
- `fork()`
- `wait()`
- Fibonacci Series
- Armstrong Numbers
- Functions
- Process Execution

## Files

```text
fibonacci-child-armstrong-parent/
├── solution.cpp
└── README.md
```

## Author

**Dhruv Saun**
