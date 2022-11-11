#include <math.h>
#include <stdio.h>

void insertionSort(int arr[], int n) {
  int key;
  for (int i = 1; i < n; i++) {
    key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}

int main() {
  int arr[] = {12, 55, 77, 32, 8, 2};
  int n = sizeof(arr) / sizeof(int);
  insertionSort(arr, n);
  printArray(arr, n);

  return 0;
}