#include <stdio.h>

void countingSort(int arr[], int n, int k) {
  int i, j, count[k];
  for (i = 0; i < k; i++) {
    count[i] = 0;
  }
  for (i = 0; i < n; i++) {
    count[arr[i]]++;
  }
  for (i = 0, j = 0; i < k; i++) {
    for (; count[i] > 0; (count[i])--) {
      arr[j++] = i;
    }
  }
}

int main() {
  int arr[] = {1, 4, 1, 2, 7, 5, 2};
  int n = sizeof(arr) / sizeof(arr[0]);
  int k = 8;
  countingSort(arr, n, k);

  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}