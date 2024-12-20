//
// Created by moezgen on 12/19/24.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

FILE *open_file(const char *filename) {
    FILE *fp;
    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Error opening file for reading %s\n", filename);
        exit(EXIT_FAILURE); // exit example
    }
}

FILE *open_file_with_abort(const char *filename) {
    FILE *fp;
    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Error opening file for reading %s\n", filename);
        abort(); // abort example
    }
}

void too_bad(void) {
    fprintf(stderr, "Too bad\n");
}

int compare_ints(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int main(void) {
    int data[5];
    srand(time(0));
    for (int i = 0; i < 5; i++) {
        data[i] = rand() % 100 + 1;
    }
    qsort(data, 5, sizeof(int), compare_ints); // qsort example
    // for (int i = 0; i < 5; i++) {
    //     printf("%d\n", data[i]);
    // }

    int target [5];

    memcpy(target, data, sizeof(int) * 5);
    for (int i = 0; i < 5; i++) {
        printf("%d\n", target[i]);
    }

    int test[5];
    memmove(test, data, sizeof(int) * 5);

    for (int i = 0; i < 5; i++) {
        printf("%d\n", test[i]);
    }

    char command [50];
    strcpy(command, "ls -l");
    char * strdup1 = strdup(command);
    char * strndup1 = strndup(strdup1, strlen("ls -l"));
    system(strndup1);
    char * getenv1 = getenv("TEST");
    printf("%s\n", getenv1);

    int n = 0;

    puts("Enter an integer: ");
    scanf("%d", &n);
    if (n < 0) {
        puts("Invalid input");
        atexit(too_bad);
        exit(EXIT_FAILURE);
    }
    return 0;
}
