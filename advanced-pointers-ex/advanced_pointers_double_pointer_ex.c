//
// Created by moezgen on 12/18/24.
//
#include <stdio.h>
#include <malloc.h>
#include <string.h>


void foo(int *p) {
    int a = 5;
    p = &a;
}
void foo_correct(int **p) {
    int a = 5;
    *p = &a;
}

void foo_char(char **p) {
    *p = malloc(255);
    strcpy(*p, "hello world!");
}

int main(void) {
    int a = 10;
    int *p1 = NULL;
    int **p2 = NULL;

    p1 = &a;
    p2 = &p1;

    printf("address of a: %u\n", &a);
    printf("address of p1: %u\n", p1);
    printf("address of p2: %u\n", p2);

    printf("value of p1: %u\n", *p1);
    printf("value of p2: %u\n", *p2);
    printf("value of **p2: %u\n", **p2);

    int * ptr = NULL;
    ptr = malloc(sizeof(int));
    * ptr = 42;
    foo_correct(&ptr);
    printf("address of ptr: %u\n", ptr);
    printf("value of *ptr: %u\n", *ptr);

    char * ptr_char = NULL;
    foo_char(&ptr_char);
    printf("value of ptr_char: %s\n", ptr_char);
    free(ptr_char);
    return 0;
}
