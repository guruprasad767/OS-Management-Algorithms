/*
Each process is assigned a priority.
The process with the highest priority is executed first.
If two processes have the same priority, they are executed according to their arrival order.
Type- Non-Preemptive
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    int id, burstTime, priority, waitingTime, turnAroundTime;
};

bool compare(Process a, Process b) {
    if (a.priority == b.priority)
        return a.id < b.id;
    return a.priority < b.priority;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);
    cout << "Enter the burst time and priority for each process:\n";
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        cin >> processes[i].burstTime >> processes[i].priority;
    }

    sort(processes.begin(), processes.end(), compare);

    processes[0].waitingTime = 0;
    for (int i = 1; i < n; i++) {
        processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
    }

    for (int i = 0; i < n; i++) {
        processes[i].turnAroundTime = processes[i].waitingTime + processes[i].burstTime;
    }

    cout << "\nProcess\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << processes[i].id << "\t" << processes[i].priority << "\t\t" << processes[i].burstTime << "\t\t" << processes[i].waitingTime << "\t\t" << processes[i].turnAroundTime << "\n";
    }

    return 0;
}
