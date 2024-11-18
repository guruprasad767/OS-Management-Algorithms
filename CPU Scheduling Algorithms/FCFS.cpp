/*
Simplest CPU scheduling algorithm.
Processes are executed in the order they arrive in the ready queue.
It operates like a queue (FIFO).
Type- Non-Preemptive
*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<int> processes(n), burstTime(n), waitingTime(n), turnAroundTime(n);
    cout << "Enter the burst time for each process:\n";
    for (int i = 0; i < n; i++)
    {
        processes[i] = i + 1;
        cin >> burstTime[i];
    }

    waitingTime[0] = 0;
    for (int i = 1; i < n; i++)
    {
        waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        turnAroundTime[i] = waitingTime[i] + burstTime[i];
    }

    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++)
    {
        cout << processes[i] << "\t" << burstTime[i] << "\t\t" << waitingTime[i] << "\t\t" << turnAroundTime[i] << "\n";
    }

    return 0;
}
