#include <stdio.h>
#include <limits.h>
#include <omp.h>

#define N 12

int main() {
    int a[N] = {25, 8, 17, 3, 42, 11, 6, 19, 2, 31, 14, 9};
    int global_min = INT_MAX;

    #pragma omp parallel
    {
        int local_min = INT_MAX;

        #pragma omp for
        for (int i = 0; i < N; i++) {
            if (a[i] < local_min)
                local_min = a[i];
        }

        // No reduction: safely combine local minima using critical
        #pragma omp critical
        {
            if (local_min < global_min)
                global_min = local_min;
        }
    }

    printf("Minimum value = %d\n", global_min);

    return 0;
}
