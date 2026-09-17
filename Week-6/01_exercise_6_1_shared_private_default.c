#include <stdio.h>
#include <omp.h>

int main() {
    int shared_value = 10;
    int private_value = 0;

    printf("Using shared() and private():\n");

    #pragma omp parallel num_threads(4) shared(shared_value) private(private_value)
    {
        int tid = omp_get_thread_num();

        private_value = tid + 100;

        printf("Thread %d: shared_value = %d, private_value = %d\n",
               tid, shared_value, private_value);
    }

    printf("\nUsing default(none):\n");

    #pragma omp parallel num_threads(4) default(none) shared(shared_value)
    {
        printf("Thread %d sees shared_value = %d\n",
               omp_get_thread_num(), shared_value);
    }

    return 0;
}
