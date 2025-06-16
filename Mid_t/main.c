#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

double f0(double a, double b, double c, double d) {
    double min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    if (d < min) min = d;
    return min;
}
double f1(double x) {
    return 5 * pow(x, 3) + 6 * pow(x, 2) - 5 * x - 9;
}
double f2(double x) {
    return sin(7 * x) * 8 - 5;
}
double f3(double x) {
    return pow(7, x) + 5;
}
double f4(double x) {
    return 1.0 / (1.0 + exp(4 * x));
}
int main(int argc, char *argv[]) {
    if (argc != 4) return 1;

    double start = atof(argv[1]);
    double end = atof(argv[2]);
    double step = atof(argv[3]);

    int pipes[4][2];
    for (int i = 0; i < 4; i++) pipe(pipes[i]);



    pid_t pids[4];
    for (int i = 0; i < 4; i++) {
        pids[i] = fork();
        if (pids[i] == 0) {
            close(pipes[i][0]);
            for (double x = start; x <= end; x += step) {
                double result;
                if (i == 0) result = f1(x);
                else if (i == 1) result = f2(x);
                else if (i == 2) result = f3(x);
                else result = f4(x);
                write(pipes[i][1], &result, sizeof(double));
            }
            close(pipes[i][1]);
            exit(0);
        } else {
            close(pipes[i][1]);
        }
    }



    FILE *file = fopen("output.csv", "w");
    fprintf(file, "x,f(x)\n");

    int steps = 0;
    for (double x = start; x <= end; x += step) steps++;

    for (int i = 0; i < steps; i++) {
        double results[4];
        for (int j = 0; j < 4; j++) read(pipes[j][0], &results[j], sizeof(double));
        double fx = f0(results[0], results[1], results[2], results[3]);
        double x = start + i * step;
        fprintf(file, "%lf,%lf\n", x, fx);
    }
    fclose(file);

    for (int i = 0; i < 4; i++) {
        close(pipes[i][0]);
        waitpid(pids[i], NULL, 0);
    }
    return 0;
}
