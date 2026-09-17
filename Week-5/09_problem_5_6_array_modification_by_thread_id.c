#include <stdio.h>
#include <omp.h>

#define N 16

int main() {
    int a[N];

    #pragma omp parallel for num_threads(4)
    for (int i = 0; i < N; i++) {
        int tid = omp_get_thread_num();
        a[i] = tid;
    }

    for (int i = 0; i < N; i++)
        printf("a[%d] = %d\n", i, a[i]);

    return 0;
}
