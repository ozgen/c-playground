#include <stdio.h>

extern int get_number();
extern int test;

typedef int* i_pointer;

int increment() {
    static int counter = 0;
    int localVar = 0;

    printf("Increment static: %d auto: %d\n", counter, localVar);
    counter++;
    localVar ++;
    return counter;
}

int main(void) {
    printf("Hello, World!\n");
    int number = 0;
    printf("%d\n", get_number());
    printf("%d\n", test);
    // printf("Enter a number: ");
    // scanf("%d", &number);
    // printf("The number is: %d\n", number);

    for (int i = 0; i < 10; i++) {
        increment();
    }

    i_pointer p; // same as int* p
    i_pointer a, *b; // same as int* a , **b
    i_pointer array[10];  // same as int *array[10]

    return 0;
}