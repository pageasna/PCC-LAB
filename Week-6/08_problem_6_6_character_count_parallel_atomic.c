#include <stdio.h>
#include <omp.h>

#define ROWS 5

int main() {
    char text[ROWS][50] = {
        "parallel programming",
        "openmp makes parallel work",
        "atomic prevents races",
        "threads share memory",
        "parallel loops are useful"
    };

    char target = 'a';
    int count = 0;

    #pragma omp parallel for
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; text[i][j] != '\0'; j++) {
            if (text[i][j] == target) {
                #pragma omp atomic
                count++;
            }
        }
    }

    printf("Character '%c' occurs %d times\n", target, count);

    return 0;
}
