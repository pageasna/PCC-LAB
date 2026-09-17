#include <stdio.h>
#include <omp.h>

#define N 100

int main() {
    int a[N], b[N];
    int serial_sum = 0;
    int parallel_sum = 0;

    for (int i = 0; i < N; i++) {
        a[i] = i;
        b[i] = 2 * i;
    }

    // Serial dot product
    for (int i = 0; i < N; i++)
        serial_sum += a[i] * b[i];

    printf("Serial dot product = %d\n", serial_sum);

    // Parallel dot product WITHOUT synchronization -> race condition
    #pragma omp parallel for
    for (int i = 0; i < N; i++)
        parallel_sum += a[i] * b[i];

    printf("Parallel dot product (race condition) = %d\n", parallel_sum);

    return 0;
}
