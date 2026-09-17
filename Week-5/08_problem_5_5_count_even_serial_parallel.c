#include <stdio.h>
#include <omp.h>

#define N 100000

int main() {
    int even_serial = 0;
    int even_parallel = 0;

    // Serial count
    for (int i = 0; i < N; i++) {
        int value = i + 1;
        if (value % 2 == 0)
            even_serial++;
    }

    // Parallel count using atomic to avoid a race condition
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        int value = i + 1;

        if (value % 2 == 0) {
            #pragma omp atomic
            even_parallel++;
        }
    }

    printf("Serial even count   = %d\n", even_serial);
    printf("Parallel even count = %d\n", even_parallel);

    return 0;
}
