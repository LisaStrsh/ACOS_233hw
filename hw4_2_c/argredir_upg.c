#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s infile outfile command [args...]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int in_fd = open(argv[1], O_RDONLY);
    if (in_fd < 0) {
        perror("open infile");
        exit(EXIT_FAILURE);
    }

    int out_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (out_fd < 0) {
        perror("open outfile");
        close(in_fd);
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        close(in_fd);
        close(out_fd);
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        if (dup2(in_fd, STDIN_FILENO) < 0) {
            perror("dup2 in_fd");
            exit(EXIT_FAILURE);
        }
        if (dup2(out_fd, STDOUT_FILENO) < 0) {
            perror("dup2 out_fd");
            exit(EXIT_FAILURE);
        }
        close(in_fd);
        close(out_fd);

        execvp(argv[3], &argv[3]);
        perror("execvp");
        exit(EXIT_FAILURE);
    } else {
        close(in_fd);
        close(out_fd);
        if (waitpid(pid, NULL, 0) < 0) {
            perror("waitpid");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
