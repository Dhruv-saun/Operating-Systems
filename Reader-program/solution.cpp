#include <iostream>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
using namespace std;

int main()
{
    int fd;
    char message[100] = {0};

    fd = open("myfifo", O_RDONLY);

    if(fd == -1)
    {
        cout << "Error opening FIFO";
        return 1;
    }

    read(fd, message, sizeof(message) - 1);

    cout << "Message received: " << message << endl;

    close(fd);

    return 0;
}