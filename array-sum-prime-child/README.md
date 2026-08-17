# Array Sum and Prime Check in Child Process

## Problem Statement

Write a C++ program to find the sum of the elements of an array within the child process and check whether the calculated sum is a prime number or not.

## Objective

- Understand process creation using `fork()`.
- Perform array operations inside a child process.
- Calculate the sum of array elements.
- Check whether the calculated sum is prime.
- Synchronize the parent and child processes using `wait()`.

## System Calls Used

- `fork()` – Creates a child process.
- `wait()` – Makes the parent process wait for the child process to complete.

## Functions Used

### `isPrime(int n)`

Checks whether the given number is a prime number.

The function returns `true` if the number is prime and `false` otherwise.

## Algorithm

1. Read the number of elements in the array.
2. Read the array elements.
3. Create a child process using `fork()`.
4. In the child process:
   - Calculate the sum of all array elements.
   - Check whether the calculated sum is prime.
   - Display the sum and the result.
5. In the parent process:
   - Wait for the child process using `wait()`.
   - Display a completion message.
6. End the program.

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
Enter number of elements: 5
Enter 5 elements: 1 2 3 4 5

Child Process
Sum = 15
15 is Not a Prime Number.

Parent Process completed.
```

## Concepts Covered

- Process Creation
- Parent and Child Processes
- Array Processing
- Process Synchronization
- Prime Number Checking
- `fork()`
- `wait()`

## Files

```text
array-sum-prime-child/
├── solution.cpp
└── README.md
```

## Author

**Dhruv Saun**