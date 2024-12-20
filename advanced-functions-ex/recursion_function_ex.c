//
// Created by moezgen on 12/6/24.
//
#include <stdio.h>

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

void up_and_down(int n);

int main(void) {
    int result = factorial(5);
    printf("%d\n", result);
    up_and_down(1);
    return 0;
}

void up_and_down(int n) {
    printf("LEVEL: %d location %p\n", n, &n);
    if (n < 4) {
        up_and_down(n + 1);
    }
    printf("LEVEL: %d location %p\n", n , &n);
}
