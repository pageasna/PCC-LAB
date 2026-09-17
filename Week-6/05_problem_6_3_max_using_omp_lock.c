#include <stdio.h>
#include <omp.h>

#define N 12

int main() {
    int a[N] = {12, 45, 7, 89, 23, 56, 3, 91, 34, 18, 67, 40};
    int max = a[0];

    omp_lock_t lock;
    omp_init_lock(&lock);

    #pragma omp parallel
    {
        int local_max = a[0];

        #pragma omp for
        for (int i = 0; i < N; i++) {
            if (a[i] > local_max)
                local_max = a[i];
        }

        omp_set_lock(&lock);

        if (local_max > max)
            max = local_max;

        omp_unset_lock(&lock);
    }

    omp_destroy_lock(&lock);

    printf("Maximum value = %d\n", max);

    return 0;
}
