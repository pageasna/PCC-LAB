#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000000

int main() {
    int *a = malloc(N * sizeof(int));
    int *b = malloc(N * sizeof(int));
    int *c = malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        a[i] = i;
        b[i] = 2 * i;
    }

    double start, end;

    // Serial addition
    start = omp_get_wtime();

    for (int i = 0; i < N; i++)
        c[i] = a[i] + b[i];

    end = omp_get_wtime();
    printf("Serial time   = %f seconds\n", end - start);

    // Parallel addition
    start = omp_get_wtime();

    #pragma omp parallel for
    for (int i = 0; i < N; i++)
        c[i] = a[i] + b[i];

    end = omp_get_wtime();
    printf("Parallel time = %f seconds\n", end - start);

    printf("c[0] = %d, c[%d] = %d\n", c[0], N - 1, c[N - 1]);

    free(a);
    free(b);
    free(c);

    return 0;
}
