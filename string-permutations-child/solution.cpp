#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <algorithm>

using namespace std;

void permutations(string str, int left, int right)
{
    if (left == right)
    {
        cout << str << endl;
        return;
    }

    for (int i = left; i <= right; i++)
    {
        swap(str[left], str[i]);

        permutations(str, left + 1, right);

        swap(str[left], str[i]); // Backtracking
    }
}

int main()
{
    pid_t pid = fork();

    if (pid < 0)
    {
        cout << "Fork failed!" << endl;
        return 1;
    }

    if (pid == 0)
    {
        // Child process
        string str;

        cout << "Child Process" << endl;
        cout << "Enter a string: ";
        cin >> str;

        cout << "\nPermutations of " << str << " are:\n";

        permutations(str, 0, str.length() - 1);
    }
    else
    {
        // Parent process
        wait(NULL);
        cout << "\nParent Process completed." << endl;
    }

    return 0;
}