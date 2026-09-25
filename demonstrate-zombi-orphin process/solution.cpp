// write a progrmam to demonstrate zombi and orphin process  \using namespace std
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;
int main() {
    pid_t pid = fork();
    if (pid < 0) {
        cerr << "Fork failed" << endl;
        return 1;
    } else if (pid == 0) {
        // Child process
        cout << "Child process (PID: " << getpid() << ") is running." << endl;
        sleep(5); // Simulate some work in the child process
        cout << "Child process (PID: " << getpid() << ") is exiting." << endl;
        exit(0); // Child exits, becomes a zombie until parent waits
    } else {
        // Parent process
        cout << "Parent process (PID: " << getpid() << ") is running." << endl;
        sleep(10); // Simulate some work in the parent process
        cout << "Parent process (PID: " << getpid() << ") is waiting for child to finish." << endl;
        wait(nullptr); // Wait for the child to finish, preventing zombie state
        cout << "Parent process (PID: " << getpid() << ") has finished waiting for child." << endl;
    }
    return 0;
}