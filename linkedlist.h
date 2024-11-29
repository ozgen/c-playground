//
// Created by moezgen on 11/27/24.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node {
    int data;
    struct Node *next;
};

void display(struct Node *head);
#endif //LINKEDLIST_H
