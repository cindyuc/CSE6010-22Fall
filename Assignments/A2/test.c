#include "node.c"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Single-linked-list being tested */
void test (){
  Node *listhead = NULL;

  listhead = Initialize();
  // Printing an empty list
  Print(listhead);

  // Searching for a value in an empty list.
  Search(listhead, 2);

  // Deleting a value from an empty list
  Delete(listhead, 0);

  // Obtaining the maximum value of an empty list
  printf("%d\n", Maximum(listhead));

  // Obtaining the predecessor of an empty list
  Predecessor(listhead, 88);

  // Obtaining the successor of an empty list
  Successor(listhead, 77);

  // Obtaining the lenght of an empty list
  Length(listhead);

  Insert(listhead, 2);
  Insert(listhead, 3);
  Insert(listhead, 8);
  Insert(listhead, 6);
  Insert(listhead, 15);
  Insert(listhead, 6);
  // Inserting a non-positive number
  Insert(listhead, -5);

  Print(listhead);
  // Searching for a value that is not in the list
  Search(listhead, 22);

  // Deleting a value that is in the list
  Delete(listhead, 2);
  Print(listhead);

  // Deleting a value that is not in the list
  Delete(listhead, 33);

  // Obtaining the predecessor of a value that is not in the list
  Predecessor(listhead, 27);
  // Obtaining the predecessor of the first value in the list
  Predecessor(listhead, 3);
  // Obtaining the predecessor of a value that is in the list
  printf("The predecessor of %d in the list is %d\n", 8,
         Predecessor(listhead, 8));

  // Obtaining the successor of a value that is not in the list
  Successor(listhead, 27);
  // Obtaining the successor of the last value in the list
  Successor(listhead, 15);
  // Obtaining the successor of a value that is in the list
  printf("The successor of %d in the list is %d.\n", 8, Successor(listhead,
  8));

  // Obtaining the maximum value of a list
  printf("The maximum value is: %d.\n", Maximum(listhead));

  // Obtaining the minimum value of a list
  printf("The minimum value is: %d.\n", Minimum(listhead));

  // Obtaining the length of the list
  printf("The length of the list is %d.\n", Length(listhead));

}

int main() {
    test();

    return 0;
}