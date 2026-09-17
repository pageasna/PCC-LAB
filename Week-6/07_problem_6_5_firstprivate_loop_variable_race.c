#include <stdio.h>
#include <omp.h>

int main() {
    int counter = 0;
    int i = 0;

    #pragma omp parallel num_threads(4) firstprivate(i) shared(counter)
    {
        // Each thread gets its own copy of i, initially 0.
        for (i = 0; i < 1000; i++) {
            // counter is shared -> race condition.
            counter++;
        }
    }

    printf("Counter (race condition) = %d\n", counter);
    printf("Expected value = 4000\n");

    return 0;
}
