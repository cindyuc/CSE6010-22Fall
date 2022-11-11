#include <stdio.h>
#include <stdlib.h>

// length of array
#define NUM 9

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void partition(int array[], int low, int high, int *result) {
    int pivot = array[high];

    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i+1], &array[high]);

    *result = i + 1;
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pivot;
        partition(array, low, high, &pivot);

        quickSort(array, low, pivot - 1);

        quickSort(array, pivot + 1, high);
    }
}

int main(){

    int integer[NUM];
    for (int i = 0; i < NUM; i++) {
        integer[i] = rand();
    }

    int length = sizeof(integer) / sizeof(integer[0]);

    // write put result into files
    FILE *file = fopen("result.txt", "w");
    if (file == NULL) {
        printf("Error opening a file \n");
        exit(1);
    }

    fprintf(file, "Unsorted data are: \n");
    printf("data are: \n");
    for (int i = 0; i < length; i++) {
        printf("%d ", integer[i]);
        fprintf(file, "%d ", integer[i]);
    }
    printf("\n");
    fprintf(file, "\n");
    

    quickSort(integer, 0, length-1);

    printf("sorted data in ascending order: \n");
    fprintf(file, "Sorted data are: \n");
    for (int i = 0; i < length; i++) {
        printf("%d ", integer[i]);
        fprintf(file, "%d ", integer[i]);
    }
    fclose(file);
}