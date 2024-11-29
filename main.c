#include <stdio.h>

#define TEST int


unsigned TEST t;

typedef int a_test;

a_test a;


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

// Example of variable length array
void alphabet_array(int size) {
    char alphabet_array[size];
    int x = 0;

    while (x < size) {
        alphabet_array[x] = 'A' + x;
        printf("alphabet_array[%d] = %c\n", x, alphabet_array[x]);
        x++;
    }
}

// Example of variable length array
int sum2d(int row, int col, int arr[row][col]) {
    int r;
    int c;
    int tot = 0;

    for (r = 0; r < row; r++) {
        for (c = 0; c < col; c++) {
            tot += arr[r][c];
        }
    }
    return tot;
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

    size_t size = 0;

    // printf("Enter array size: ");
    // scanf("%d", &size);
    // float values[size];

    alphabet_array(5);
    alphabet_array(10);
    return 0;
}