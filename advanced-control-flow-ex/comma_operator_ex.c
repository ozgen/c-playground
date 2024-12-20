//
// Created by moezgen on 12/5/24.
//
#include <stdio.h>


int func1() {
    return 1;
}

int func2() {
    return 2;
}

int main() {
    int i = 0;
    int sum = 0;
    int data[] = {1, 2, 3, 4, 5};
    while (i < 5) {
        sum += data[i], ++i;
    }
    printf("sum = %d\n", sum);

    int j = (func1(), func2()); // calculate func1 assign j and calculate func2 and assign j
    printf("j = %d\n", j);

    int z = 0;
    int y = 0;
    int x = (y = 3, (z = ++y + 2) + 5);
    printf("x = %d y = %d z = %d\n", x, y, z);

    return 0;
}
