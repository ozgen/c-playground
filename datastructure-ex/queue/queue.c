//
// Created by moezgen on 12/20/24.
//

#include <stdio.h>
#include <stdlib.h>

struct QNode {
    int key;
    struct QNode *next;
};

struct Queue {
    struct QNode *front;
    struct QNode *rear;
};

struct QNode *newNode(int key) {
    struct QNode *node = (struct QNode *) malloc(sizeof(struct QNode));
    node->key = key;
    node->next = NULL;
    return node;
}

struct Queue *initQueue() {
    struct Queue *q = (struct Queue *) malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(struct Queue *q, int key) {
    struct QNode *node = newNode(key);
    if (q->rear == NULL) {
        q->front = q->rear = node;
        return;
    }
    q->rear->next = node;
    q->rear = node;
}

int deQueue(struct Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }

    struct QNode *temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    int key = temp->key;
    free(temp);
    return key;
}


int main() {
    struct Queue *q = initQueue();
    enQueue(q, 10);
    enQueue(q, 20);
    enQueue(q, 30);
    enQueue(q, 40);
    int res = deQueue(q);
    printf("%d\n", res);
    res = deQueue(q);
    printf("%d\n", res);
    res = deQueue(q);
    printf("%d\n", res);
    res = deQueue(q);
    printf("%d\n", res);
    res = deQueue(q);
    printf("%d\n", res);
    return 0;
}
