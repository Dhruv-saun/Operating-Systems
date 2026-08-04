#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        cout << "Fork failed!" << endl;
        return 1;
    }

    if (pid == 0) {
        cout << "Child Process (Odd Numbers):" << endl;
        for (int i = 1; i <= 20; i += 2)
            cout << i << " ";
        cout << endl;
    } else {
        wait(NULL);
        cout << "Parent Process (Even Numbers):" << endl;
        for (int i = 2; i <= 20; i += 2)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}