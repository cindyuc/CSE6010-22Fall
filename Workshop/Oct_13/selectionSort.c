#include <stdio.h>

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void selectionSort(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    int min_idx = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }
    if (min_idx != i) {
      swap(&arr[i], &arr[min_idx]);
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

  selectionSort(arr, n);
  printArray(arr, n);

  return 0;
}