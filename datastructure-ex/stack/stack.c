//
// Created by moezgen on 12/20/24.
//
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *top;

void push(int x) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  if (temp == NULL) {
    printf("Stack Overflow\n");
    return;
  }
  temp->data = x;
  temp->next = top;
  top = temp;
}

int pop() {
  if (top == NULL) {
    printf("Stack Underflow\n");
    return -1;
  }

  struct node *temp = top;
  int x = temp->data;
  top = temp->next;
  free(temp);
  return x;
}

int peek() {
  if (top == NULL) {
    printf("Stack is empty\n");
    return -1;
  }
  return top->data;
}

int main() {
  top = NULL;

  push(5);
  push(6);
  push(3);
  push(4);

  printf("%d\n", pop());

  printf("%d\n", peek());

  return 0;
}
