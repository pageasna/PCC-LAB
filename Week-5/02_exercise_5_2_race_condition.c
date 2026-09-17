#include <stdio.h>
#include <omp.h>

int main() {
    int sum = 0;
    int n = 100;

    // Serial sum
    for (int i = 1; i <= n; i++)
        sum += i;

    printf("Serial sum = %d\n", sum);

    // Parallel sum WITHOUT synchronization -> race condition
    sum = 0;

    #pragma omp parallel for
    for (int i = 1; i <= n; i++)
        sum += i;

    printf("Parallel sum (race condition) = %d\n", sum);

    return 0;
}
