#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s command1 command2 [args...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int pipefd[2];
    if (pipe(pipefd) < 0) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid_t pid1 = fork();
    if (pid1 < 0) {
        perror("fork for command1");
        exit(EXIT_FAILURE);
    }

    if (pid1 == 0) {
        if (dup2(pipefd[1], STDOUT_FILENO) < 0) {
            perror("dup2 stdout");
            exit(EXIT_FAILURE);
        }
        close(pipefd[0]);
        close(pipefd[1]);
        execlp(argv[1], argv[1], NULL);
        perror("execlp command1");
        exit(EXIT_FAILURE);
    }

    pid_t pid2 = fork();
    if (pid2 < 0) {
        perror("fork for command2");
        exit(EXIT_FAILURE);
    }

    if (pid2 == 0) {
        if (dup2(pipefd[0], STDIN_FILENO) < 0) {
            perror("dup2 stdin");
            exit(EXIT_FAILURE);
        }
        close(pipefd[0]);
        close(pipefd[1]);
        execvp(argv[2], &argv[2]);
        perror("execvp command2");
        exit(EXIT_FAILURE);
    }

    close(pipefd[0]);
    close(pipefd[1]);

    int status;
    while (wait(&status) > 0 || errno != ECHILD) {
        if (WIFEXITED(status)) {
            printf("WEXITSTATUS(%d)\n", WEXITSTATUS(status));
        }
    }

    return 0;
}
