#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main() {
    for (int i = 1; i <= 3; i++) {
        pid_t pid = fork();

        if (pid == 0) {
            cout << "Child " << i << endl;
            cout << "PID: " << getpid() << endl;
            cout << "PPID: " << getppid() << endl;
            return 0;
        }
    }

    for (int i = 1; i <= 3; i++)
        wait(NULL);

    return 0;
}