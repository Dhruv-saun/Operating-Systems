#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <cstring>
using namespace std;

int main()
{
    key_t key;
    int shmid;
    char *str;

    key = ftok("progfile", 65);

    shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    if(shmid == -1)
    {
        cout << "Error creating shared memory";
        return 1;
    }

    str = (char*) shmat(shmid, NULL, 0);

    if(str == (char*) -1)
    {
        cout << "Error attaching shared memory";
        return 1;
    }

    cout << "Enter a message: ";
    cin.getline(str, 1024);

    cout << "Message written successfully!" << endl;

    shmdt(str);

    return 0;
}