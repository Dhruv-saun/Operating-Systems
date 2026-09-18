// wacp to create input.txt (file name will be given in runtime) in parent process and write your name university rol no and class roll no in it and then read same file in child process and print the content pass the file name using pipe or we can say runtime.
#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>
using namespace std;
int main() {
    string filename, name, universityRollNo, classRollNo;
    cout << "Enter file name: ";
    cin >> filename;
    cin.ignore();
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter university roll number: ";
    getline(cin, universityRollNo);
    cout << "Enter class roll number: ";
    getline(cin, classRollNo);
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("Pipe failed");
        return 1;
    }
    pid_t pid = fork();
    if (pid == -1) {
        perror("Fork failed");
        return 1;
    }
    if (pid > 0) {
        // Parent process: create and write to the file
        close(pipefd[0]);
        ofstream file(filename);
        if (!file) {
            cerr << "Unable to create file.\n";
            return 1;
        }
        file << "Name: " << name << '\n';
        file << "University Roll No: " << universityRollNo << '\n';
        file << "Class Roll No: " << classRollNo << '\n';
        file.close();
        // Send the file name to the child through the pipe
        write(pipefd[1], filename.c_str(), filename.length() + 1);
        close(pipefd[1]);
        wait(nullptr);
    } else {
        // Child process: receive the file name and read the file
        close(pipefd[1]);
        char receivedFilename[256] = {};
        read(pipefd[0], receivedFilename, sizeof(receivedFilename));
        close(pipefd[0]);
        ifstream file(receivedFilename);
        if (!file) {
            cerr << "Unable to open file.\n";
            return 1;
        }
        cout << "\nContent of the file:\n";
        string line;
        while (getline(file, line)) {
            cout << line << '\n';
        }
        file.close();
    }
    return 0;
}