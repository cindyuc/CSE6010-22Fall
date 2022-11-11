#include "sort.h"

void heapifyAirports(Airport *airports, int n, int i) {
  int smallest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && airports[left].delayAll < airports[smallest].delayAll) {
    smallest = left;
  }

  if (left < n && airports[left].delayAll == airports[smallest].delayAll &&
      strcmp(airports[left].abbrev, airports[smallest].abbrev) > 0) {
    smallest = left;
  }

  if (right < n && airports[right].delayAll < airports[smallest].delayAll) {
    smallest = right;
  }

  if (right < n && airports[right].delayAll == airports[smallest].delayAll &&
      strcmp(airports[right].abbrev, airports[smallest].abbrev) > 0) {
    smallest = right;
  }

  if (smallest != i) {
    Airport temp = airports[i];
    airports[i] = airports[smallest];
    airports[smallest] = temp;
    heapifyAirports(airports, n, smallest);
  }
}

void heapSortAirports(Airport *airports, int n) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapifyAirports(airports, n, i);
  }
  for (int i = n - 1; i >= 0; i--) {
    Airport temp = airports[0];
    airports[0] = airports[i];
    airports[i] = temp;
    heapifyAirports(airports, i, 0);
  }
}

void insertionSortAirports(Airport *airports, int n) {
  for (int i = 1; i < n; i++) {
    Airport temp = airports[i];
    int j = i - 1;
    while (j >= 0 && airports[j].delayAll <= temp.delayAll) {
      // when more than one airport has the same delayAll, sort them in
      // alphabetical order
      if (airports[j].delayAll == temp.delayAll &&
          strcmp(airports[j].abbrev, temp.abbrev) < 0) {
        break;
      }
      airports[j + 1] = airports[j];
      j--;
    }
    airports[j + 1] = temp;
  }
}

void mergeAirports(Airport *airports, int l, int m, int r) {
  // create L <- airports[l,...,m] and R <- airports[m+1,...,r]
  int n1 = m - l + 1;
  int n2 = r - m;
  Airport L[n1], R[n2];

  for (int i = 0; i < n1; i++) {
    L[i] = airports[l + i];
  }
  for (int j = 0; j < n2; j++) {
    R[j] = airports[m + 1 + j];
  }

  int i = 0, j = 0, k = l;

  // pick the larger elements among L and R, and put it in airports[k]
  while (i < n1 && j < n2) {
    if (L[i].delayAll > R[j].delayAll) {
      airports[k] = L[i];
      i++;
    } else if (L[i].delayAll < R[j].delayAll) {
      airports[k] = R[j];
      j++;
    } else {
      if (strcmp(L[i].abbrev, R[j].abbrev) <= 0) {
        airports[k] = L[i];
        i++;
      } else {
        airports[k] = R[j];
        j++;
      }
    }
    k++;
  }

  // when we run out of elements in L or R, pick the remaining elements and put
  // it in airports[k]
  while (i < n1) {
    airports[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    airports[k] = R[j];
    j++;
    k++;
  }
}

void mergeSortAirports(Airport *airports, int l, int r) {
  if (l < r) {
    int m = l + ((r - l) >> 1);
    mergeSortAirports(airports, l, m);
    mergeSortAirports(airports, m + 1, r);
    mergeAirports(airports, l, m, r);
  }
}