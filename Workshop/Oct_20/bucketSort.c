#include <stdio.h>
#include <stdlib.h>

#define NBUCKET 10

/**In Bucket Sort, we assume that the N numbers to sort are drawn from a uniform
 * distribution over [0,1)**/

typedef struct Node {
  float data;
  struct Node *next;
} Node;

void InsertionSort(Node *list) {
  if (list == NULL || list->next == NULL) {
    // printf("the bucket is empty.\n");
    return;
  }

  Node *l1 = list;
  Node *l2 = list->next;
  l1->next = NULL;
  while (l2 != NULL) {
    if (l1->data > l2->data) {
      Node *tmp = l2;
      l2 = l2->next;
      tmp->next = l1;
      l1 = tmp;
      continue;
    }

    Node *ptr;
    for (ptr = l1; ptr->next != NULL; ptr = ptr->next) {
      if (ptr->next->data > l2->data) {
        break;
      }
    }

    if (ptr->next != NULL) {
      Node *tmp = l2;
      l2 = l2->next;
      tmp->next = ptr->next;
      ptr->next = tmp;
      continue;
    } else {
      ptr->next = l2;
      l2 = l2->next;
      ptr->next->next = NULL;
      continue;
    }
  }
  list = l1;
}

// n is the array size
void BucketSort(float arr[], int n) {
  int i, j;
  Node **buckets = malloc(sizeof(Node *) * NBUCKET);

  // initialize empty buckets
  for (int i = 0; i < NBUCKET; i++) {
    buckets[i] = NULL;
  }

  // fill the buckets with respective elements
  //   printf("fill the buckets with respective elements.\n");
  for (int i = 0; i < n; i++) {
    Node *current = malloc(sizeof(Node));
    // get index in bucket
    int bi;
    for (bi = 0; bi < NBUCKET; bi++) {
      if (arr[i] >= (1.0 / NBUCKET * bi) &&
          arr[i] < (1.0 / NBUCKET * (bi + 1))) {
        break;
      }
    }

    current->data = arr[i];
    current->next = buckets[bi];
    buckets[bi] = current;
  }

  // print the buckets along with their elements

  // sort the elements of each bucket
  //   printf("sort the elements of each bucket.\n");

  for (int i = 0; i < NBUCKET; i++) {
    InsertionSort(buckets[i]);
  }

  // put sorted elements on arr
  //   printf("put sorted elements on arr.\n");

  for (int i = 0, j = 0; i < NBUCKET; i++) {
    Node *current = buckets[i];
    while (current) {
      arr[j] = current->data;
      j++;
      current = current->next;
    }
  }

  // print sorted array
  for (int i = 0; i < n; i++) {
    printf("%f ", arr[i]);
  }
  printf("\n");
}

int main() {
  float arr[] = {0.72, 0.17, 0.39, 0.26, 0.78, 0.94, 0.21, 0.12, 0.23, 0.68};
  int n = sizeof(arr) / sizeof(float);
  BucketSort(arr, n);

  return 0;
}