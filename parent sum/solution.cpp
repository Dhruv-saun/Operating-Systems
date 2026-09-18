// wap to calculate sum of array in parent proceess and check the calcuated sum is prime or not in child process
#include <bits/stdc++.h>
#include <sys/wait.h>
using namespace std;
int main(){
    
    int arr[5], sum = 0;
    cout << "Enter 5 elements of array: ";
    for(int i = 0; i < 5; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    cout << "Sum of array is: " << sum << endl;

    int pid = fork();
    if(pid < 0){
        cout << "Fork failed" << endl;
        return 1;
    }
    else if(pid == 0){
        // child process
        bool isPrime = true;
        if(sum <= 1) isPrime = false;
        for(int i = 2; i <= sqrt(sum); i++){
            if(sum % i == 0){
                isPrime = false;
                break;
            }
        }
        if(isPrime) cout << "The sum is prime." << endl;
        else cout << "The sum is not prime." << endl;
    }
    else{
        // parent process
        wait(NULL);
    }
    return 0;
}