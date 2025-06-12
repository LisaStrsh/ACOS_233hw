#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_THREADS 4

int *array;
int N;
long long sum = 0;
pthread_mutex_t sum_mutex;

typedef struct {
    int start;
    int end;
} ThreadData;

void *worker(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    long long local_sum = 0;

    for (int i = data->start; i < data->end; ++i) {
        local_sum += array[i];
    }

    pthread_mutex_lock(&sum_mutex);
    sum += local_sum;
    pthread_mutex_unlock(&sum_mutex);

    return NULL;
}

int main() {
    scanf("%d", &N);
    if (N < 16) {
        return 1;
    }

    array = malloc(sizeof(int) * N);
    if (array == NULL) {
        return 1;
    }

    srand(time(NULL));
    for (int i = 0; i < N; ++i) {
        array[i] = rand() % 100;
    }

    for (int i = 0; i < N; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");

    pthread_t threads[NUM_THREADS];
    ThreadData data[NUM_THREADS];
    int chunk_size = N / NUM_THREADS;

    pthread_mutex_init(&sum_mutex, NULL);

    for (int i = 0; i < NUM_THREADS; ++i) {
        data[i].start = i * chunk_size;
        data[i].end = (i == NUM_THREADS - 1) ? N : (i + 1) * chunk_size;
        pthread_create(&threads[i], NULL, worker, &data[i]);
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&sum_mutex);

    printf("%lld\n", sum);

    free(array);
    return 0;
}
