#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cmath>
#include <string>

using namespace std;

void fibonacci(int n) {
    if (n <= 0) {
        return;
    }

    int a = 0, b = 1;

    cout << a << "\t";

    if (n > 1) {
        cout << b << "\t";
    }

    for (int i = 2; i < n; i++) {
        int c = a + b;
        a = b;
        b = c;

        cout << c << "\t";
    }

    cout << endl;
}

bool armstrong(int n, int digits) {
    int original = n;
    int sum = 0;

    while (n > 0) {
        int rem = n % 10;
        sum += static_cast<int>(pow(rem, digits));
        n /= 10;
    }

    return sum == original;
}

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        cout << "Fork failed!" << endl;
        return 1;
    }

    if (pid == 0) {
        int n;

        cout << "Enter n for Fibonacci series: ";
        cin >> n;

        cout << "Fibonacci Series: ";
        fibonacci(n);
    }
    else {
        wait(NULL);

        int n;

        cout << "Enter n for Armstrong number range: ";
        cin >> n;

        cout << "Armstrong Numbers: ";

        for (int i = 0; i <= n; i++) {
            string s = to_string(i);

            if (armstrong(i, s.length())) {
                cout << i << "\t";
            }
        }

        cout << endl;
    }

    return 0;
}