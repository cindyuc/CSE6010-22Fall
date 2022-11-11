#include <stdio.h>

int maxInArray(int arr[], int n) {
  int max = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

void countingSort(int arr[], int n, int place) {
  int output[n + 1];
  int max = (arr[0] / place) % 10;

  for (int i = 1; i < n; i++) {
    if (((arr[i] / place) % 10) > max) {
      max = arr[i];
    }
  }

  int count[max + 1];

  for (int i = 0; i < max; i++) {
    count[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    count[(arr[i] / place) % 10]++;
  }

  for (int i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }

  for (int i = n - 1; i >= 0; i--) {
    output[count[(arr[i] / place) % 10] - 1] = arr[i];
    count[(arr[i] / place) % 10]--;
  }

  for (int i = 0; i < n; i++) {
    arr[i] = output[i];
  }
}

void radixSort(int arr[], int n) {
  int max = maxInArray(arr, n);

  for (int place = 1; max / place > 0; place *= 10) {
    countingSort(arr, n, place);
  }
}

int main() {
  int arr[] = {23, 55, 12, 90, 200, 899, 45, 67, 34, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  radixSort(arr, n);

  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}