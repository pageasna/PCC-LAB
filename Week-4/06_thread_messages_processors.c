#include <stdio.h>
#include <omp.h>

int main()
{
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        int threads = omp_get_num_threads();
        int processors = omp_get_num_procs();

        printf("Hello from Thread %d of %d. "
               "Processors available: %d\n",
               id, threads, processors);
    }

    return 0;
}
