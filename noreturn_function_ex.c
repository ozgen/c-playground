//
// Created by moezgen on 12/17/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>

noreturn void test_exit(void);

int main(void) {
   test_exit();
    return 0;
}

void test_exit(void) {
  printf("Test exit\n");
  exit(0);
}

