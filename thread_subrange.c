//Divide a given range to multiple subranges in threads and return the prime numbers present in the subrange to main thread
//for this code, no. of subranges/threads = 10
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<stdbool.h>
#define N 100

bool isPrime(int x) {
        int i;
        if (x==2 ) return true;
        else if (x<2 || x%2==0) return false;
        else for(i=3;i<=(x/2); i+=2) {
                if(x%i==0) return false;
        }
        return true;
}

void* findprimes(void* args) {
        int* x = (int*)args;
        int i, j=0;
        int *primes = (int*)malloc(sizeof(int)*(N/10));
        printf("Calculating primes in thread...\n");
        for(i=x[0]; i<x[1]; i++) {
                if(isPrime(i)) {
                primes[j]=i;
                j++; }
        }
        pthread_exit((void*)primes); //return void type pointer to array
}

void main() {
        int i, count = 0, range[2] = {0,0}; //declare an array to pass {lower limit, upper limit}
        pthread_t th;
        int *res; //to store value exit value of thread
        printf("Creating threads in main...");
        for(i=0; i<N; i+=(N/10)) {
                range[0]=i; //set lower limit
                range[1]=i+(N/10); //set upper limit
                printf("\nThread %d: ", count);
                pthread_create(&th, NULL, findprimes, (void*)range); //create threads with same thread id and function
                pthread_join(th, (void**)&res); //treat address of res as a pointer to (void*)
                int j=0;
                while(res[j]!=0) {
                        printf("%d ", res[j]); //print result
                        j++;
                }
                count++;
        }
}
