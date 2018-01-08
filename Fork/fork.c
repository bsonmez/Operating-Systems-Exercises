
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int fib(int n){
    if (n <= 1)
        return n;
    return fib(n-1) + fib(n-2);
}

int main() {
    int a;
    int i;
    pid_t pid;
    
    pid = fork();

    if(pid<0) {
        fprintf(stderr, "fork failed");
        return 1;
    } else if(pid == 0) {
        printf("enter a number: ");
        scanf("%d", &a);
        for (i = 0; i<a; i++) {
            printf("%d ", fib(i));
        }
    } else {
        wait(NULL);
        printf("child complete\n");
    }
    return 0;
}
