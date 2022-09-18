#include "node.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Initialize a singly-linked-list, which contains only one dummy head
 * @return The new singly linked list, or NULL if memory allocation failed
 **/
Node *Initialize() {
  Node *listhead = malloc(sizeof(Node));

  if (listhead) {
    listhead->data = 0;
    listhead->next = NULL;
  }
  return listhead;
}

/**
 * @brief Insert data into the list with increasing sorted order.
 * @return 0 if the operation succeeds, or 1 if it fails
 **/
int Insert(Node *listhead, int data) {
  if (data <= 0) {
    printf("The inserted data must be positive. \n");

    return 1;
  }

  Node *new_node = malloc(sizeof(Node));
  if (new_node == NULL) {
    return 1;
  } else {
    new_node->data = data;
  }

  Node *tmp_node = listhead;

  while (tmp_node->next && tmp_node->next->data < data) {
    tmp_node = tmp_node->next;
  }
  new_node->next = tmp_node->next;
  tmp_node->next = new_node;

  return 0;
}

/**
 * @brief Search for the value of data within the list;
 * @return a pointer to the first node with data or NULL if the data is not
 *present.
 **/
Node *Search(Node *listhead, int data) {
  Node *tmp_node = listhead->next;
  
  if (tmp_node == NULL) {
    printf("The list is empty.\n");
    return tmp_node;
  }

  while (tmp_node) {
    if (tmp_node->data == data) {
      return tmp_node;
    }

    // Since single-linked tables are sorted in increasing order, it is
    // impossible to find a quilified data once the value of the current data is
    // greater than the given value.
    if (tmp_node->data > data) {
      break;
    }
    tmp_node = tmp_node->next;
  }

  printf("The data value is not found in the list.\n");
  return NULL;
}

/**
 * @brief Remove all nodes with data from the list if they are in the list.
 * @return 0 if deletion succeeds, or 1 if it fails.
 **/
int Delete(Node *listhead, int data) {
  Node *tmp_node = listhead;
  Node *deletN;
  int count = 0;

  if (tmp_node->next == NULL) {
    printf("The list is empty.\n");
    return 1;
  }

  while (tmp_node && tmp_node->next) {
    if (tmp_node->next->data == data) {
      deletN = tmp_node->next;
      tmp_node->next = deletN->next;
      free(deletN);
      count++;
    }
    tmp_node = tmp_node->next;
  }

  if (count == 0) {
    printf("The data value is not found in the list.\n");
    return 1;
  }

  return 0;
}

/**
 * @brief find and return the minimum value in the list.
 * @return the minimum value of all the nodes in the list, or 0 if the list is
 *empty
 **/
int Minimum(Node *listhead) {
  if (listhead->next == NULL) {
    return 0;
  } else {
    return listhead->next->data;
  }
}

/**
 * @brief find and return the maximum value in the list.
 * @return the maximum value of all the nodes in the list, or 0 if the list is
 * empty
 **/
int Maximum(Node *listhead) {
  if (listhead->next == NULL) {
    return 0;
  }

  Node *tmp_node = listhead->next;
  while (tmp_node && tmp_node->next) {
    tmp_node = tmp_node->next;
  }

  return tmp_node->data;
}

/**
 * @brief find and return the data value of the node that precedes the node with
 * given data value in the list
 * @return the predecessor's data value, or 0 if the list is empty/the specified
 * data value is not found/the specified data value is the first node in the list
 **/
int Predecessor(Node *listhead, int data) {
  int predecessor = 0;
  Node *tmp_node = listhead->next;

  if (tmp_node == NULL) {
    printf("The list is empty.\n");
    return predecessor;
  } else if (tmp_node->data == data) {
    printf("The specified data value is the first node in the list.\n");
    return predecessor;
  }

  while (tmp_node && tmp_node->next) {
    if (tmp_node->next->data == data) {
      predecessor = tmp_node->data;

      return predecessor;
    }
    // Since single-linked tables are sorted in increasing order, it is
    // impossible to find a quilified data once the value of the current data is
    // greater than the given value.
    if (tmp_node->data > data) {
      break;
    }
    tmp_node = tmp_node->next;
  }

  printf("The specified data value is not found.\n");
  return predecessor;
}

/**
 * @brief find and return the data value of the node that follows the node with
 * given data value in the list
 * @return the predecessor's data value, or 0 if the list is empty/the specified
 * data value is not found/the specified data value is the last node in the
 * list
 **/
int Successor(Node *listhead, int data) {
    int successor = 0;
    Node *tmp_node = listhead->next;

    if (tmp_node == NULL) {
        printf("The list is empty.\n");
        return successor;
    }

    while (tmp_node) {
        if (tmp_node->data == data) {
            if (tmp_node->next == NULL) {
                printf("The specified data value is the last node in the list.\n");
                return successor;
            }

            successor = tmp_node->next->data;
            return successor;
        }
        // Since single-linked tables are sorted in increasing order, it is
        // impossible to find a quilified data once the value of the current data is
        // greater than the given value.
        if (tmp_node->data > data) {
            break;
        }
        tmp_node = tmp_node->next;
    }

    printf("The specified data value is not found.\n");
    return successor;
}

/**
 * @brief Insert data into the list that begins with listhead.
 * @return the number of iterms in the list, or 0 if the list is empty or NULL.
 **/
unsigned int Length(Node *listhead) {
  int list_length = 0;
  Node *tmp_node = malloc(sizeof(Node));
  if (tmp_node == NULL) {
    return 1;
  }

  tmp_node = listhead->next;

  while (tmp_node) {
    list_length++;
    tmp_node = tmp_node->next;
  }
  free(tmp_node);

  return list_length;
}

/**
 * @brief print the data items stored in the list in order from first to last.
 **/
void Print(Node *listhead) {
    Node *tmp_node = listhead->next;

    if (tmp_node) {
        while (tmp_node) {
            printf("%d ", tmp_node->data);
            tmp_node = tmp_node->next;
        }
        printf("\n");
    } else {
        printf("The list is empty.\n");
    }
}

/**
 * @brief Delete the list that begins with listhead.
 **/
void Finalize(Node *listhead) {
    Node *deletN;

    if (listhead) {
        while (listhead->next) {
            deletN = listhead->next;
            listhead->next = deletN->next;

            free(deletN);
        }
        free(listhead);
    }
}