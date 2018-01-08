# Banker’s Algorithm

Banker’s Algorithm is a dynamic deadlock-avoidance technique which can be used in Operating Systems in order to detect and prevent possible deadlock situations caused by the unproper allocation of resources that are requested by several different processes simultaneously

Consider the system at below with five processes P0 through P4 with three different resource types that are A,B and C where the resource type A has ten (10) instances, B has five (5) instances and C has seven (7) instances.

Process | Allocation | Max | Available
------------ | ------------ | ------------- | -------------
Process | A B C |  A B C |  A B C
P0 | 0 1 0 | 8 5 3 | 3 3 2
P1 | 2 0 0 | 3 2 2 | 
P2 | 3 0 2 | 9 0 2 | 
P3 | 2 1 1 | 6 2 2 | 
P4 | 0 0 2 | 4 5 3 | 

Write a program that implements the Banker’s Algorithm as it is used to determine whether such system is in a safe state or not based on the provided data at above.

As an output, the program should compute that whether the system is in a safe state or not. If the system is in a safe state, then the program should find and print one possible execution sequence for these five processes. Otherwise, if the system encounters with an unsafe state, it should also inform the user that the system is not in a safe state.



