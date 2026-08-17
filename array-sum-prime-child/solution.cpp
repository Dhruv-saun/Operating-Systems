#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

bool isPrime(int n)
{
    if (n < 2)
        return false;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    pid_t pid = fork();

    if (pid < 0)
    {
        cout << "Fork failed!" << endl;
        return 1;
    }

    if (pid == 0)
    {
        // Child process
        int sum = 0;

        for (int i = 0; i < n; i++)
            sum += arr[i];

        cout << "\nChild Process" << endl;
        cout << "Sum = " << sum << endl;

        if (isPrime(sum))
            cout << sum << " is a Prime Number." << endl;
        else
            cout << sum << " is Not a Prime Number." << endl;
    }
    else
    {
        // Parent process
        wait(NULL);
        cout << "\nParent Process completed." << endl;
    }

    return 0;
}