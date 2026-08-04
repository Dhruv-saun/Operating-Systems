#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    pid_t pid1 = fork();

    if (pid1 < 0) {
        cout << "Fork failed!" << endl;
        return 1;
    }

    if (pid1 == 0) {

        pid_t pid2 = fork();

        if (pid2 < 0) {
            cout << "Fork failed!" << endl;
            return 1;
        }

        if (pid2 == 0) {
            long long fact = 1;

            for (int i = 1; i <= n; i++)
                fact *= i;

            cout << "Innermost Child Process (Factorial): " << fact << endl;
        }
        else {
            wait(NULL);

            cout << "Middle Child Process (Fibonacci): ";

            int a = 0, b = 1;

            for (int i = 0; i < n; i++) {
                cout << a << " ";
                int c = a + b;
                a = b;
                b = c;
            }

            cout << endl;
        }
    }
    else {
        wait(NULL);

        int sum = 0;

        for (int i = 1; i <= n; i++)
            sum += i;

        cout << "Parent Process (Sum): " << sum << endl;
    }

    return 0;
}