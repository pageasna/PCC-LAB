#include <stdio.h>
#include <omp.h>

#define N 1000

int main() {
    int sum = 0;

    #pragma omp parallel for
    for (int i = 1; i <= N; i++) {
        #pragma omp atomic
        sum += i;
    }

    printf("Sum using atomic = %d\n", sum);

    return 0;
}
