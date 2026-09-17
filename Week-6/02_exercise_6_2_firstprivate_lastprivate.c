#include <stdio.h>
#include <omp.h>

int main() {
    int start = 10;
    int last = -1;

    #pragma omp parallel for num_threads(4) firstprivate(start) lastprivate(last)
    for (int i = 0; i < 8; i++) {
        int value = start + i;

        printf("Thread %d: i = %d, value = %d\n",
               omp_get_thread_num(), i, value);

        last = value;
    }

    printf("\nAfter parallel loop:\n");
    printf("start = %d\n", start);
    printf("last  = %d\n", last);

    return 0;
}
