#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
using namespace std;

struct message
{
    long msg_type;
    char msg_text[100];
};

int main()
{
    key_t key;
    int msgid;
    message msg;

    key = ftok("progfile", 65);

    msgid = msgget(key, 0666 | IPC_CREAT);

    if(msgid == -1)
    {
        cout << "Error creating message queue";
        return 1;
    }

    msgrcv(msgid, &msg, sizeof(msg.msg_text), 1, 0);

    cout << "Message received: " << msg.msg_text << endl;

    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}