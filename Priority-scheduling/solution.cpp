#include <iostream>
using namespace std;

int main()
{
    int n, temp;
    int bt[20], wt[20], tat[20], p[20], pr[20];
    float avg_wt = 0, avg_tat = 0;

    cout << "Enter number of processes: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cout << "Enter burst time for P" << i + 1 << ": ";
        cin >> bt[i];

        cout << "Enter priority for P" << i + 1 << ": ";
        cin >> pr[i];

        p[i] = i + 1;
    }

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(pr[i] > pr[j])
            {
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    wt[0] = 0;

    for(int i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for(int i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    avg_wt /= n;
    avg_tat /= n;

    cout << "\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n";

    for(int i = 0; i < n; i++)
    {
        cout << "P" << p[i] << "\t"
             << bt[i] << "\t\t"
             << pr[i] << "\t\t"
             << wt[i] << "\t\t"
             << tat[i] << "\n";
    }

    cout << "\nAverage Waiting Time = " << avg_wt;
    cout << "\nAverage Turnaround Time = " << avg_tat;

    return 0;
}