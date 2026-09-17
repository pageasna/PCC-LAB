#include <stdio.h>
#include <omp.h>

int sum = 0;

int main()
{
    omp_set_num_threads(4);

    #pragma omp parallel
    {
        int id = omp_get_thread_num();

        #pragma omp atomic
        sum += id;
    }

    printf("Sum of thread IDs = %d\n", sum);

    return 0;
}
