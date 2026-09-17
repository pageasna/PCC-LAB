#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000000

int main() {
    int *a = malloc(N * sizeof(int));

    double start, end;

    // Serial initialization
    start = omp_get_wtime();

    for (int i = 0; i < N; i++)
        a[i] = i;

    end = omp_get_wtime();
    printf("Serial time   = %f seconds\n", end - start);

    // Parallel initialization
    start = omp_get_wtime();

    #pragma omp parallel for
    for (int i = 0; i < N; i++)
        a[i] = i;

    end = omp_get_wtime();
    printf("Parallel time = %f seconds\n", end - start);

    printf("First = %d, Last = %d\n", a[0], a[N - 1]);

    free(a);
    return 0;
}
