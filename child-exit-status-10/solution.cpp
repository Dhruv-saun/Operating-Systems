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
        cout << "Child Process" << endl;
        exit(10);
    } else {
        int status;
        wait(&status);

        if (WIFEXITED(status)) {
            cout << "Parent Process" << endl;
            cout << "Child exited with status: " << WEXITSTATUS(status) << endl;
        }
    }

    return 0;
}