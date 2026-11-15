#include <iostream>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <cstring>
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

    msg.msg_type = 1;

    cout << "Enter a message: ";
    cin.getline(msg.msg_text, 100);

    msgsnd(msgid, &msg, sizeof(msg.msg_text), 0);

    cout << "Message sent successfully!" << endl;

    return 0;
}