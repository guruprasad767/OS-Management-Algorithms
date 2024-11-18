/*
Process with the smallest burst time is executed first.
Minimizes the average waiting and turnaround times compared to other algorithms.
May cause starvation for longer processes.
Type- Non-Preemptive
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process
{
    int id, burstTime, waitingTime, turnAroundTime;
};

bool compare(Process a, Process b)
{
    return a.burstTime < b.burstTime;
}

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);
    cout << "Enter the burst time for each process:\n";
    for (int i = 0; i < n; i++)
    {
        processes[i].id = i + 1;
        cin >> processes[i].burstTime;
    }

    sort(processes.begin(), processes.end(), compare);

    processes[0].waitingTime = 0;
    for (int i = 1; i < n; i++)
    {
        processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
    }

    for (int i = 0; i < n; i++)
    {
        processes[i].turnAroundTime = processes[i].waitingTime + processes[i].burstTime;
    }

    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++)
    {
        cout << processes[i].id << "\t" << processes[i].burstTime << "\t\t" << processes[i].waitingTime << "\t\t" << processes[i].turnAroundTime << "\n";
    }

    return 0;
}
