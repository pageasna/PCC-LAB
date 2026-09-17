#include <stdio.h>
#include <omp.h>

int main() {
    int n = 12;

    #pragma omp parallel for num_threads(4)
    for (int i = 0; i < n; i++) {
        printf("Thread %d processes element %d\n",
               omp_get_thread_num(), i);
    }

    return 0;
}
