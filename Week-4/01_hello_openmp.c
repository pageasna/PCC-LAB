#include <stdio.h>
#include <omp.h>

int main()
{
    #pragma omp parallel
    {
        printf("Hello OpenMP World! Thread %d\n", omp_get_thread_num());
    }

    return 0;
}
