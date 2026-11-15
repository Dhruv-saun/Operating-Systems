#include <iostream>
using namespace std;

int main()
{
    int n, f, pos;
    int pages[50], frames[10], time[10];
    int faults = 0, hits = 0, counter = 0;
    int flag;

    cout << "Enter number of pages: ";
    cin >> n;

    cout << "Enter page reference string: ";
    for(int i = 0; i < n; i++)
        cin >> pages[i];

    cout << "Enter number of frames: ";
    cin >> f;

    for(int i = 0; i < f; i++)
    {
        frames[i] = -1;
        time[i] = 0;
    }

    for(int i = 0; i < n; i++)
    {
        flag = 0;

        for(int j = 0; j < f; j++)
        {
            if(frames[j] == pages[i])
            {
                flag = 1;
                hits++;
                counter++;
                time[j] = counter;
                break;
            }
        }

        if(flag == 0)
        {
            pos = 0;

            for(int j = 0; j < f; j++)
            {
                if(frames[j] == -1)
                {
                    pos = j;
                    break;
                }

                if(time[j] < time[pos])
                    pos = j;
            }

            frames[pos] = pages[i];
            counter++;
            time[pos] = counter;
            faults++;
        }

        cout << "\n" << pages[i] << "\t";

        for(int j = 0; j < f; j++)
        {
            if(frames[j] != -1)
                cout << frames[j] << " ";
            else
                cout << "- ";
        }

        if(flag == 0)
            cout << "\tPage Fault";
        else
            cout << "\tHit";
    }

    cout << "\n\nTotal Page Faults = " << faults;
    cout << "\nTotal Page Hits = " << hits;

    return 0;
}