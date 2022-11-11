#include <stdbool.h>
#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort(int arr[], int n) {
  bool swapped = true;
  while (swapped) {
    swapped = false;
    for (int i = 0; i < n - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        swap(&arr[i], &arr[i + 1]);
        swapped = true;
      }
    }
  }
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main() {
  int arr[] = {2, 5, 3, 1, 4};
  int n = sizeof(arr) / sizeof(int);

  bubbleSort(arr, n);
  printArray(arr, n);

  return 0;
}