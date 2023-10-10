//pass message from parent to child process using pipe
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#define MAX 50
void main() {
        int fd[2];
        char buff[MAX], message[MAX];
        pipe(fd);
        pid_t id=fork();
        if(id>0) {
                printf("This is Parent Process.\nEnter message: ");
                scanf("%s", buff);
                write(fd[1], buff, strlen(buff)+1);
                sleep(10);

        }
        else {
                sleep(5);
                printf("This is child process. Message received by child: ");
                fflush(stdout);
                int n = read(fd[0], message, MAX);
                write(1, message, n);
        }
}
