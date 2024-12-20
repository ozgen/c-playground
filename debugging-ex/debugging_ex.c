//
// Created by moezgen on 12/18/24.
//
#include <stdio.h>
#include <stdlib.h>

struct date {
    int day;
    int month;
    int year;
};

struct date foo(struct date d) {
    ++d.day;
    return d;
}


int main(void) {
    struct date today = {18, 12, 2024};
    int array[5] = {1, 2, 3, 4, 5};
    struct date *newdate, foo();
    char *str = "This is a test";
    int i = 3;
    newdate = (struct date *) malloc(sizeof(struct date));
    newdate->day = 19;
    newdate->month = 12;
    newdate->year = 2024;
    today = foo(today);
    free(newdate);

    return 0;
}
