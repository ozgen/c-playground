//
// Created by moezgen on 11/27/24.
//

#ifndef INSTERT_H
#define INSTERT_H

struct Node;
struct Node* create_node(int data);
void b_insert(struct Node** head, int data);
void n_insert(struct Node** head, int data, int pos);
void e_insert(struct Node** head, int data);
#endif //INSTERT_H
