//
// Created by moezgen on 12/20/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main() {
  alarm(3);
  for (int i = 0; i < 5; i++) {
    printf("%d\n", i);
    sleep(1);
  }

  printf("Testing Signal SIGSTOP!\n");
  raise(SIGSTOP);
  printf("Testing Signal SIGCONT!\n");
  return 0;
}