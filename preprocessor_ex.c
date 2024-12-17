//
// Created by moezgen on 12/6/24.
//
#include <stdio.h>

#define JUST_CHECK
#define LIMIT 4
#pragma GCC warning "warning"
// #pragma GCC error "error"
#pragma GCC message "hello_message"
int main(void) {
    int i;
    int total = 0;

    for (i = 0; i < LIMIT; i++) {
        total += i * 2 * i + 1;
#ifdef JUST_CHECK
        printf("%d\n", total);
#endif
    }
    return 0;
}
