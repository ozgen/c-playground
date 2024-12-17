//
// Created by moezgen on 12/6/24.
//
#include <stdio.h>

struct owner {
    int id;
};
struct company {
    char name[50];
    char address[50];
};

struct car_data {
    char make[50];
    int status;
    // example of anonymous union
    union {
        struct owner owner;
        struct company company;
    } data;
};

union car {
    int i_value;
    float f_value;
    char c_value[20];
};

union mixed {
    int i_value;
    float f_value;
    char c_value;
};

int main(void) {
    union car car1, *car2;

    printf("Memory size occupied by car: %zu\n", sizeof(car1));
    car2 = &car1;
    car2 -> i_value = 100;
    printf("car2.i_value = %i\n", (*car2).i_value);
    printf("car2->i_value = %i\n", car2->i_value);

    union mixed m1;
    m1.c_value = 'c';
    printf("m1.c_value = %c\n", m1.c_value);

    union mixed m2 = { 12, 12.6, 'c'}; // others do not set, only 12 is set to i_value
    printf("m2.i_value = %i\n m2.f_value = %f\n m2.c_value = %c\n", m2.i_value,  m2.f_value, m2.c_value);

    return 0;
}
