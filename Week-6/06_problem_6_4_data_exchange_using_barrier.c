#include <stdio.h>
#include <omp.h>

#define THREADS 4

int main() {
    int data[THREADS];

    #pragma omp parallel num_threads(THREADS) shared(data)
    {
        int tid = omp_get_thread_num();

        // Each thread writes its own value.
        data[tid] = tid * 10;

        // Wait until every thread has finished writing.
        #pragma omp barrier

        // Now every thread can safely read all values.
        printf("Thread %d reads: ", tid);

        for (int i = 0; i < THREADS; i++)
            printf("%d ", data[i]);

        printf("\n");
    }

    return 0;
}
