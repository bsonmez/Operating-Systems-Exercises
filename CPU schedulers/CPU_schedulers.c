#include <stdio.h>

void fcfs();
void shortestJob();
void rr();
void priority();

int main() {
    
    int i;
    int processes[5] = {1,2,3,4,5};
    int burstTimes[5] = {10,1,2,3,5};
    int priorities[5] = {3,1,4,5,2};
    
    printf("Execution sequences of processes: \n");
    printf("\nProcess    Burst Time    Priority");
    for(i=0;i<5;i++)
    {
        printf("\nP[%d]\t   %d\t\t    %d",processes[i],burstTimes[i],priorities[i]);
    }
    printf("\n");
    
    fcfs();
    shortestJob();
    priority();
    rr();
    return 0;
}

void fcfs() {
    
    int i = 0;
    
    printf("FCFS Algorithm: ");
    
    for(i=0; i<5; i++) {
        printf("P[%d] ", i+1);
    }
    
    printf("\n");
}

void shortestJob() {
    int i,j,pos,temp;
    int processes[5] = {1,2,3,4,5};
    int burstTimes[5] = {10,1,2,3,5};
    
    for(i=0;i<5;i++) {
        pos=i;
        for(j=i+1;j<5;j++) {
            if(burstTimes[j]<burstTimes[pos])
            pos=j;
        }
        
        temp=burstTimes[i];
        burstTimes[i]=burstTimes[pos];
        burstTimes[pos]=temp;
        
        temp=processes[i];
        processes[i]=processes[pos];
        processes[pos]=temp;
    }
    
    printf("Shortest Job First Algorithm: ");
    
    for(i=0; i<5; i++) {
        printf("P[%d] ", processes[i]);
    }
    
    printf("\n");
}

void rr() {
    int i = 0;
    int remain = 21;
    int quantum = 0;
    
    int rt[5] = {10,1,2,3,5};
    
    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);
    
    printf("Round Robin Algorithm: ");
    
    while(remain > 0) {
        
        if(rt[i] > 0) {
            printf("P[%d] ", i+1);
            rt[i] = rt[i] - quantum;
            remain = remain - quantum;
        }
        
        i++;
        if(i==5) {
            i=0;
        }
    }
    
    
}

void priority() {
    int i,j,pos,temp;
    
    int processes[5] = {1,2,3,4,5};
    int burstTimes[5] = {10,1,2,3,5};
    int priorities[5] = {3,1,4,5,2};
    
    
    //sorting burst time, priority and process number in ascending order using selection sort
    for(i=0;i<5;i++){
        pos=i;
        for(j=i+1;j<5;j++){
            if(priorities[j]<priorities[pos])
            pos=j;
        }
        
        temp=priorities[i];
        priorities[i]=priorities[pos];
        priorities[pos]=temp;
        
        temp=burstTimes[i];
        burstTimes[i]=burstTimes[pos];
        burstTimes[pos]=temp;
        
        temp=processes[i];
        processes[i]=processes[pos];
        processes[pos]=temp;
    }
    
    
    printf("Priority Scheduling Algorithm: ");
    
    for(i=4; i>=0; i--) {
        printf("P[%d] ", processes[i]);
    }
    
    printf("\n");
    
}
