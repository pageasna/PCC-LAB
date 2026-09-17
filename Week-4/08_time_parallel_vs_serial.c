#include <stdio.h>
#include <omp.h>

int main()
{
    long long n = 100000000;
    double sum = 0.0;
    double start, end;

    /* Serial execution */
    start = omp_get_wtime();

    for (long long i = 0; i < n; i++)
    {
        sum += 1.0 / (i + 1);
    }

    end = omp_get_wtime();

    printf("Serial result: %f\n", sum);
    printf("Serial time: %f seconds\n", end - start);

    /* Parallel execution */
    sum = 0.0;

    start = omp_get_wtime();

    #pragma omp parallel for reduction(+:sum)
    for (long long i = 0; i < n; i++)
    {
        sum += 1.0 / (i + 1);
    }

    end = omp_get_wtime();

    printf("Parallel result: %f\n", sum);
    printf("Parallel time: %f seconds\n", end - start);

    return 0;
}
