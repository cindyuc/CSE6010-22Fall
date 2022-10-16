#include "node.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char instructions[] =
      "Please type command sequences to build your own single-linked list as "
      "follows: \n\n"
      "p \t Demonstration of linked list framework, initial is null\n"
      "new \t Create empty linked list\n"
      "i \t Insert a new node with value\n"
      "del \t Delete a node with value\n"
      "f \t Search a node with value\n"
      "max \t Get the maximum value in linked list\n"
      "min \t Get the minimum value in the linked list\n"
      "pred \t Get the predecessor of a specific node with value\n"
      "suc \t Get the successor of a specific node with value\n"
      "l \t Get the length of this linked list\n"
      "q \t Clear current linked list and quit program\n";

  printf("%s", instructions);

  // bool initial = false;
  printf("please enter your command sequence: \n");
  Node *listhead = NULL;

  // enforce user to initialize a empty linked list first.
  while (1) {
    char input;
    scanf("%20s", &input);

    if (strcmp(&input, "new") == 0) {
      printf("initialize successfully.\n");
      listhead = Initialize();
      break;
    }
    printf("please initialize a empty linked list first. \n");
  }


  while (1) {
    char input;
    printf("please enter your command sequence: \n");
    scanf("%20s", &input);
    // printf("%s", &input);

    if (strcmp(&input, "p") == 0) {
      Print(listhead);
    } else if (strcmp(&input, "i") == 0) {
      int value;

      printf("enter the value you want to insert: \n");
      scanf("%d", &value);

      Insert(listhead, value);
    } else if (strcmp(&input, "del") == 0) {
      int value;

      printf("enter the value you want to delet: \n");
      scanf("%d", &value);

      Delete(listhead, value);
    } else if (strcmp(&input, "f") == 0) {
      int value;

      printf("enter the value you want to search: \n");
      scanf("%d", &value);

      Search(listhead, value);
    } else if (strcmp(&input, "max") == 0) {
      printf("find max.");
      int max_value = Maximum(listhead);
      printf("the maximum value in the list is %d\n", max_value);
    } else if (strcmp(&input, "min") == 0) {
      int min_value = Minimum(listhead);
      printf("the maximum value in the list is %d\n", min_value);
    } else if (strcmp(&input, "pred") == 0) {
      int value;

      printf("enter the value you want to search for a predecessor: \n");
      scanf("%d", &value);

      Predecessor(listhead, value);
    } else if (strcmp(&input, "suc") == 0) {
      int value;

      printf("enter the value you want to search for a successor: \n");
      scanf("%d", &value);

      Successor(listhead, value);
    } else if (strcmp(&input, "l") == 0) {
      unsigned int len = Length(listhead);
      printf("the length of list is %u\n", len);
    } else if (strcmp(&input, "q") == 0) {
      Finalize(listhead);
      break;
    } else {
      printf("invalid input, please try again.\n");
    }
  }

  return 0;
}