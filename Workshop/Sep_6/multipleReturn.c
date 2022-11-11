#include <stdio.h>



// return the maximum value in an array;
double maximum_value(double one_array[], int length) {
    if (length == 0) {
        printf("The array is empty");
        return -1.0;
    }

    double max = one_array[0];
    for (int i = 1; i < length; ++i) {
        if (one_array[i] > max) {
            max = one_array[i];
        }
    }

    return max;
}

int max_value_index(double one_array[], int length) {
    if (length == 0) {
        printf("The array is empty");
        return -1.0;
    }

    int index = 0;
    double max_value = one_array[0];
    for (int i = 0; i < length; ++i) {
        if (one_array[i] > max_value) {
            index = i;
            max_value = one_array[i];
        }
    }

    return index;
}

int main() {
    double a[6] = {1.0, 3.0, 12.0, 5.0, 4.0, 8.0};
    int length = sizeof(a) / sizeof(a[0]);
    double max_value = maximum_value(a, length);
    int maximum_value_index = max_value_index(a, length);

    printf("The maximum value in the array is %f, who's index is %d", max_value, maximum_value_index);
    
    
    return 0;
}