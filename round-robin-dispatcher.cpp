#include <iostream>
#include <queue>
using namespace std;
struct Process {
 int id;
 int at;
 int bt;
 int remain_time;
};
// Round-robin dispatcher
void dispatcher(Process processes[], int n, int tq) {
 queue<Process> q;
 int current_time = 0;
 int total_time = 0;
 int comp = 0;
 for (int i = 0; i < n; i++) {
 q.push(processes[i]);
 }
 while (comp < n) {
 Process current_process = q.front();
 q.pop();
 int processing_time = min(tq, current_process.remain_time);
 current_time += processing_time;
 current_process.remain_time -= processing_time;

 if (current_process.remain_time == 0) {
 comp++;
 cout << "Process " << current_process.id << " completed at time "
<< current_time << endl;
 } else {

 q.push(current_process);
 }
 total_time += processing_time;
 }
 double avg_waiting_time = (double) total_time / n;
 cout << "Average waiting time: " << avg_waiting_time << endl;
10
}
// Main function
int main() {
 int n;
 int tq;

 cout << "Enter the number of processes: ";
 cin >> n;
 Process processes[n];
 for (int i = 0; i < n; i++) {
 processes[i].id = i + 1;
 cout << "Enter arrival time and burst time for process " <<
processes[i].id << ": ";
 cin >> processes[i].at >> processes[i].bt;
 processes[i].remain_time = processes[i].bt;
 }
 cout << "Enter time quanta : ";
 cin >> tq;
 dispatcher(processes, n, tq);
 return 0;
}