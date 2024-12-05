//
// Created by moezgen on 12/5/24.
//
#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>

jmp_buf buf;

void my_func(void) {
    printf("in my function\n");
    longjmp(buf, 1);
    /* NOT REACHED*/
    printf("test\n");
}

int main() {

    if (setjmp(buf)) {
        printf("back in main\n");
    } else {
        printf("first time to run \n");
        my_func();
    }

    // int i = setjmp(buf);
    // printf("i= %d\n", i);
    // if (i !=0) {
    //     exit(0);
    // }
    // longjmp(buf, 45);
    //
    // printf("Does the longjmp work?\n");

    return 0;
}
