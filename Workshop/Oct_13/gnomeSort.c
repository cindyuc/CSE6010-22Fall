#include <stdio.h>

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void gnomeSort(int arr[], int n) {
  int idx = 0;
  while (idx < n) {
    if (idx == 0 || arr[idx] >= arr[idx - 1]) {
      idx++;
    } else {
      swap(&arr[idx], &arr[idx - 1]);
      idx--;
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

  gnomeSort(arr, n);
  printArray(arr, n);

  return 0;
}
