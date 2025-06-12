#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid1 = fork();
    if (pid1 == 0) {
        printf("Hello from Child 1\n");
        pid_t pid2 = fork();
        if (pid2 == 0) {
            printf("Hello from Grandchild\n");
        } else {
            wait(NULL);
            printf("Child 1 finished waiting for Grandchild\n");
        }
    } else {
        wait(NULL);
        printf("Parent finished waiting for Child 1\n");
    }
    return 0;
}
