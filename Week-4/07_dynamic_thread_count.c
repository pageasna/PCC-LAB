#include <stdio.h>
#include <omp.h>

int main()
{
    int n;

    printf("Enter number of threads: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Number of threads must be positive.\n");
        return 1;
    }

    omp_set_num_threads(n);

    #pragma omp parallel
    {
        printf("Hello from thread %d of %d\n",
               omp_get_thread_num(),
               omp_get_num_threads());
    }

    return 0;
}
