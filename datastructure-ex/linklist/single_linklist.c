//
// Created by moezgen on 12/19/24.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef node_t *ListNodePtr;

void insert(ListNodePtr *head, int data);
void insertAtEnd(ListNodePtr *head, int data);
void insertAtStart(ListNodePtr *head, int data);
int deleteNode(ListNodePtr *head, int data);
void deleteAtStart(ListNodePtr *head);
int isEmpty(ListNodePtr head);
void display(ListNodePtr head);

int main(void) {
    ListNodePtr head = NULL;

    insert(&head, 10);
    insert(&head, 11);
    insert(&head, 123);
    insert(&head, 23);
    insert(&head, 1234);
    insertAtEnd(&head, 45);

    deleteAtStart(&head);
    deleteNode(&head, 45);

    display(head);

    return 0;
}

void insert(ListNodePtr *head, int data) {
    ListNodePtr newNode = (ListNodePtr) malloc(sizeof(node_t));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        ListNodePtr temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtEnd(ListNodePtr *head, int data) {
    insert(head, data);
}

void insertAtStart(ListNodePtr *head, int data) {
    ListNodePtr newNode = (ListNodePtr) malloc(sizeof(node_t));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = data;
    newNode->next = *head;

    *head = newNode;
}

int deleteNode(ListNodePtr *head, int data) {
    if (*head == NULL) {
        return 0; // List is empty
    }

    ListNodePtr temp = *head;

    if (temp->data == data) { // Deleting the head node
        *head = temp->next;
        free(temp);
        return 1;
    }

    while (temp->next != NULL && temp->next->data != data) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        return 0; // Node not found
    }

    ListNodePtr toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
    return 1;
}

void deleteAtStart(ListNodePtr *head) {
    if (*head == NULL) {
        return; // List is empty
    }

    ListNodePtr temp = *head;
    *head = (*head)->next;
    free(temp);
}

int isEmpty(ListNodePtr head) {
    return head == NULL;
}

void display(ListNodePtr head) {
    ListNodePtr temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
