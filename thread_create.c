//create a thread
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void* thread1 (void* args) {
        printf("Inside Thread:");
        int i;
        for(i=0; i<5; i++) {
                printf("%d ", i);
                sleep(1);
        }
}

void main() {
        int i;
        pthread_t th1;
        pthread_create(&th1, NULL, thread1, NULL);
        pthread_join(th1, NULL);
        printf("Inside Main:\n");
        for(i=10; i<=15; i++) {
                printf("%d ", i);
                sleep(1);
        }
}
