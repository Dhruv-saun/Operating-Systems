#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    pid_t pid = fork();

    if (pid < 0) {
        cout << "Fork failed!" << endl;
        return 1;
    }

    if (pid == 0) {
        cout << "Child Process ID: " << getpid() << endl;
        cout << "Parent Process ID: " << getppid() << endl;

        if (n % 2 == 0) {
            cout << n << " is Even" << endl;
        } else {
            cout << n << " is Odd" << endl;
        }
    } 
    else {
        wait(NULL);

        cout << "Parent Process ID: " << getpid() << endl;
        cout << "Child Process ID: " << pid << endl;

        long long factorial = 1;

        for (int i = 1; i <= n; i++) {
            factorial *= i;
        }

        cout << "Factorial: " << factorial << endl;
    }

    return 0;
}