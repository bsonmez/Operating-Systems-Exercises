#include <pthread.h> 
#include <stdio.h>

#define size 3
int arr[size];
void *runner(void *param);
void *sort(void *param);
void *printsort(void *param);

int main(int argc, char *argv[]) {
    pthread_t tid;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    
    pthread_create(&tid,&attr,runner,argv[1]);
    pthread_join(tid,NULL);
    pthread_create(&tid,&attr,sort,argv[1]);
    pthread_join(tid,NULL);
    pthread_create(&tid,&attr,printsort,argv[1]);
    pthread_join(tid,NULL);
    
}

void *runner(void *param){
    int i;
    for (i = 0; i < size; i++) {
        printf("enter a number: ");
        scanf("%d", &arr[i]);
    }
    pthread_exit(0);
}

void *sort(void *param) {
    int i,j,temp=0;
    for(i = 0; i < size; i++) {
        for(j = 0; j < (size-1); j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    pthread_exit(0);
}

void *printsort(void *param) {
    printf("Numbers are sorted: %d %d %d\n", arr[0],arr[1],arr[2]);
    pthread_exit(0);
}
