#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
using namespace std;

int main()
{
    key_t key;
    int shmid;
    char *str;

    key = ftok("progfile", 65);

    shmid = shmget(key, 1024, 0666);

    if(shmid == -1)
    {
        cout << "Error accessing shared memory";
        return 1;
    }

    str = (char*) shmat(shmid, NULL, 0);

    if(str == (char*) -1)
    {
        cout << "Error attaching shared memory";
        return 1;
    }

    cout << "Message received: " << str << endl;

    shmdt(str);

    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}