#include <stdio.h>
#include <omp.h>

int main()
{
    omp_set_num_threads(4);

    #pragma omp parallel
    {
        int active = omp_get_num_threads();

        #pragma omp single
        {
            printf("Number of active threads = %d\n", active);
        }
    }

    return 0;
}
