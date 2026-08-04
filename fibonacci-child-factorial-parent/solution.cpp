#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    pid_t pid = fork();

    if (pid < 0) {
        cout << "Fork failed!" << endl;
        return 1;
    }

    if (pid == 0) {
        cout << "Child Process (Fibonacci Series):" << endl;

        int a = 0, b = 1;

        for (int i = 0; i < n; i++) {
            cout << a << " ";
            int c = a + b;
            a = b;
            b = c;
        }

        cout << endl;
    }
    else {
        wait(NULL);
        long long fact = 1;

        for (int i = 1; i <= n; i++)
            fact *= i;

        cout << "Parent Process (Factorial): " << fact << endl;
    }

    return 0;
}