/*
Places a process in the largest available memory partition.
Lead to inefficient memory usage and fragmentation over time.
*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int numBlocks, numProcesses;
    cout << "Enter the number of memory blocks: ";
    cin >> numBlocks;

    vector<int> blockSize(numBlocks);
    cout << "Enter the size of each memory block:\n";
    for (int i = 0; i < numBlocks; i++)
    {
        cin >> blockSize[i];
    }

    cout << "Enter the number of processes: ";
    cin >> numProcesses;

    vector<int> processSize(numProcesses);
    cout << "Enter the size of each process:\n";
    for (int i = 0; i < numProcesses; i++)
    {
        cin >> processSize[i];
    }

    vector<int> allocation(numProcesses, -1);
    for (int i = 0; i < numProcesses; i++)
    {
        int worstIdx = -1;
        for (int j = 0; j < numBlocks; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx])
                {
                    worstIdx = j;
                }
            }
        }
        if (worstIdx != -1)
        {
            allocation[i] = worstIdx + 1;
            blockSize[worstIdx] -= processSize[i];
        }
    }

    cout << "\nProcess\tProcess Size\tBlock Allocated\n";
    for (int i = 0; i < numProcesses; i++)
    {
        cout << i + 1 << "\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i];
        else
            cout << "Not Allocated";
        cout << "\n";
    }

    return 0;
}
