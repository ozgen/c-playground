#include <complex.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define __STDC_WANT_LIB_EXT1__ 1
#define TEST int


unsigned TEST t;

typedef int a_test;

a_test a;


extern int get_number();
extern int test;

typedef int* i_pointer;

int increment() {
    static int counter = 0;
    int localVar = 0;

    printf("Increment static: %d auto: %d\n", counter, localVar);
    counter++;
    localVar ++;
    return counter;
}

// Example of variable length array
void alphabet_array(int size) {
    char alphabet_array[size];
    int x = 0;

    while (x < size) {
        alphabet_array[x] = 'A' + x;
        printf("alphabet_array[%d] = %c\n", x, alphabet_array[x]);
        x++;
    }
}

// Example of variable length array
int sum2d(int row, int col, int arr[row][col]) {
    int r;
    int c;
    int tot = 0;

    for (r = 0; r < row; r++) {
        for (c = 0; c < col; c++) {
            tot += arr[r][c];
        }
    }
    return tot;
}

// flesible array members
struct s {
    int arraySize;
    int array[];
};


int main(void) {
    printf("Hello, World!\n");
    int number = 0;
    printf("%d\n", get_number());
    printf("%d\n", test);
    // printf("Enter a number: ");
    // scanf("%d", &number);
    // printf("The number is: %d\n", number);

    for (int i = 0; i < 10; i++) {
        increment();
    }

    i_pointer p; // same as int* p
    i_pointer a, *b; // same as int* a , **b
    i_pointer array[10];  // same as int *array[10]

    size_t size = 0;

    // printf("Enter array size: ");
    // scanf("%d", &size);
    // float values[size];

    alphabet_array(5);
    alphabet_array(10);

    // flexible array members
    int desireArraySize = 10;
    struct s *ptr;

    ptr = malloc(sizeof(struct s) + desireArraySize * sizeof(int));
    // end flexible array member

    // complex number
    #ifdef __STDC_NO_COMPLEX__
    #else
        printf("complex are supported.\n");

        double complex cx = 1.0 + 3.0* I;
        double complex cy = 1.0 - 4.0* I;
        printf("cx_r = %f,cx_i = %f, cy_r = %f, cy_i = %f\n",creal(cx), cimag(cx), creal(cy), cimag(cy));
        double complex cz = cpow(cx, cy);
        printf("cz_r = %f, cz_i = %f\n",creal(cz), cimag(cz));
        double complex z1 = I * I;     // imaginary unit squared
        printf("I * I = %.1f%+.1fi\n", creal(z1), cimag(z1));

        double complex z2 = pow(I, 2); // imaginary unit squared
        printf("pow(I, 2) = %.1f%+.1fi\n", creal(z2), cimag(z2));

        double PI = acos(-1);
        double complex z3 = exp(I * PI); // Euler's formula
        printf("exp(I*PI) = %.1f%+.1fi\n", creal(z3), cimag(z3));

        double complex z4 = 1+2*I, z5 = 1-2*I; // conjugates
        printf("(1+2i)*(1-2i) = %.1f%+.1fi\n", creal(z4*z5), cimag(z4*z5));
    #endif

    return 0;
}