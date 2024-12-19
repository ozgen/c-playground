//
// Created by moezgen on 12/19/24.
//
#include <stdio.h>
#include <assert.h>

#define NDEBUG 1
static_assert(1 == 1, "Compile-time assertion failed: This should fail.");

int main(void) {
    int y = 5;

    for (int i = 0; i < 10; i++) {
        printf("i = %d and y = %d\n", i, y);
        // assert(i<y);
    }


    return 0;
}
