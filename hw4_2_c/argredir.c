#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s infile outfile command arg1 arg2 ...\n", argv[0]);
        exit(1);
    }

    pid_t pid = fork();
    if (pid == 0) {
        int in_fd = open(argv[1], O_RDONLY);
        int out_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);
        if (in_fd < 0 || out_fd < 0) {
            perror("open");
            exit(1);
        }

        dup2(in_fd, STDIN_FILENO);
        dup2(out_fd, STDOUT_FILENO);
        close(in_fd);
        close(out_fd);

        execvp(argv[3], &argv[3]);
        perror("execvp");
        exit(1);
    } else {
        int status;
        waitpid(pid, &status, 0);
    }

    return 0;
}
