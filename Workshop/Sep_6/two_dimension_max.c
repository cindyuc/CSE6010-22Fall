#include <stdio.h>

struct Number {
    double value;
    int index_i;
    int index_j;
};

struct Number max_number(double *array, int len_i, int len_j) {
    struct Number max = {.value = *(double *)array, .index_i = 0, .index_j = 0};

    for (int i = 0; i < len_i; ++i) {
        for (int j = 0; j < len_j; ++j) {
         if (max.value < *(array + len_j*i + j)) {
            max.value = *(array + len_j*i + j);
            max.index_i = i;
            max.index_j = j;
         }
        }
    }

    return max;
}

int main() {
    double a[5][2] = {{1.0, 4.0}, {3.3, 5.7}, {1.4, 5.6}, {2.5, 7.4}, {2.5, 67.5}};
    int len_i = sizeof(a) / sizeof(a[0]);
    int len_j = sizeof(a[0]) / sizeof(a[0][0]);

    struct Number max = max_number(&a[0][0], len_i, len_j);
    printf("The maximum number in the array is %f, and its indexes are %d, %d.", max.value, max.index_i, max.index_j);
    
    return 0;
}