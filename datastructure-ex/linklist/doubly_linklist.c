//
// Created by moezgen on 12/20/24.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} node_t;

typedef node_t *ListNodePtr;

void insertAtEnd(ListNodePtr *head, int data) {
  ListNodePtr newNode = (ListNodePtr)malloc(sizeof(node_t));
  if (newNode == NULL) {
    printf("Memory allocation failed in insertAtEnd\n");
    exit(EXIT_FAILURE);
  }

  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;

  if (*head == NULL) {
    *head = newNode;
    return;
  }

  ListNodePtr tmp = *head;
  while (tmp->next != NULL) {
    tmp = tmp->next;
  }

  tmp->next = newNode;
  newNode->prev = tmp;
}

void insertAtStart(ListNodePtr *head, int data) {
  ListNodePtr newNode = (ListNodePtr)malloc(sizeof(node_t));
  if (newNode == NULL) {
    printf("Memory allocation failed in insertAtStart\n");
    exit(EXIT_FAILURE);
  }
  newNode->data = data;
  newNode->next = NULL;
  newNode->prev = NULL;

  if (*head == NULL) {
    *head = newNode;
    return;
  }

  newNode->next = *head;
  (*head)->prev = newNode;
  *head = newNode;
}

void insertAfter(ListNodePtr *head, int dataAfter, int data) {
  if (*head == NULL) {
    printf("List is empty, cannot insert after %d\n", dataAfter);
    return;
  }

  ListNodePtr tmp = *head;

  while (tmp != NULL && tmp->data != dataAfter) {
    tmp = tmp->next;
  }

  if (tmp == NULL) {
    printf("Node with data %d not found\n", dataAfter);
    return;
  }

  ListNodePtr newNode = (ListNodePtr)malloc(sizeof(node_t));
  if (newNode == NULL) {
    printf("Memory allocation failed in insertAfter\n");
    exit(EXIT_FAILURE);
  }

  newNode->data = data;

  newNode->next = tmp->next;
  if (tmp->next != NULL) {
    tmp->next->prev = newNode;
  }
  newNode->prev = tmp;
  tmp->next = newNode;
}


void deleteAtEnd(ListNodePtr *head) {
  if (*head == NULL) {
    printf("List is empty, nothing to delete\n");
    return;
  }

  ListNodePtr tmp = *head;

  while (tmp->next != NULL) {
    tmp = tmp->next;
  }

  if (tmp->prev == NULL) {
    *head = NULL;
  } else {
    tmp->prev->next = NULL;
  }

  free(tmp);
}


void deleteAtStart(ListNodePtr *head) {
  ListNodePtr tmp = *head;
  if (tmp == NULL) {
    printf("Memory allocation failed in deleteAtStart\n");
    exit(EXIT_FAILURE);
  }
  *head = (*head)->next;
  (*head)->prev = NULL;
  free(tmp);
}

void display(ListNodePtr *head) {
  ListNodePtr tmp = *head;
  if (tmp == NULL) {
    printf("Memory allocation failed in display\n");
    exit(EXIT_FAILURE);
  }
  while (tmp != NULL) {
    printf("%d -> ", tmp->data);
    tmp = tmp->next;
  }
    printf("NULL\n");
}

int main() {
  ListNodePtr list = NULL;
  insertAtEnd(&list, 1);
  insertAtStart(&list, 2);
  insertAtEnd(&list, 3);
  insertAtEnd(&list, 4);
  insertAtEnd(&list, 5);
  insertAtEnd(&list, 6);
  insertAfter(&list, 4, 10);
  insertAtEnd(&list, 7);
  deleteAtEnd(&list);
  display(&list);
}
