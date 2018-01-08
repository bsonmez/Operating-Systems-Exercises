
# CPU Schedulers

Consider the following set of processes, with the length of the CPU burst given in miliseconds :

Process | Burst Time | Priority 
------------ | ------------ | ------------- 
P1 | 10 | 3 
P2 | 1 | 1 | 
P3 | 2 | 4 | 
P4 | 3 | 5 | 
P5 | 5| 2 | 

The processes are assumed to have arrived in the order P1, P2, P3, P4, P5, all at time 0.
Write a program that __simulates__ and schedules these five processes by using the scheduling algorithms as listed below:

- Round Robin (RR) (Time quantum should be chosen by the user)
- Priority ( P)

For each scheduling algorithm, calculate and print the execution sequence of these processes.


