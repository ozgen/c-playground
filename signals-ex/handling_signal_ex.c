//
// Created by moezgen on 12/20/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler_dividedbyzero(int sig);

int main() {
    int res = 0;
    int v1 = 123;
    int v2 = 0;
    void (*signal_handler)(int);

    signal_handler = signal(SIGFPE, handler_dividedbyzero);
    if (signal_handler == SIG_ERR) {
        perror("signal error");
        return 1;
    }
    res = v1 / v2;
    printf("res: %d\n", res);
    return 0;
}

void handler_dividedbyzero(int sig) {
    if (sig == SIGFPE) {
        printf("Divide by zero exception - SIGFPE: %d\n", sig);
        exit(0);
    }
}
