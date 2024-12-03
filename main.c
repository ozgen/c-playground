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

typedef int *i_pointer;

int increment() {
    static int counter = 0;
    int localVar = 0;

    printf("Increment static: %d auto: %d\n", counter, localVar);
    counter++;
    localVar++;
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

// flexible array members
struct s {
    int arraySize;
    int array[];
};

//designated initializers
struct point {
    int x;
    int y;
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
    i_pointer array[10]; // same as int *array[10]

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

    double complex cx = 1.0 + 3.0 * I;
    double complex cy = 1.0 - 4.0 * I;
    printf("cx_r = %f,cx_i = %f, cy_r = %f, cy_i = %f\n", creal(cx), cimag(cx), creal(cy), cimag(cy));
    double complex cz = cpow(cx, cy);
    printf("cz_r = %f, cz_i = %f\n", creal(cz), cimag(cz));
    double complex z1 = I * I; // imaginary unit squared
    printf("I * I = %.1f%+.1fi\n", creal(z1), cimag(z1));

    double complex z2 = pow(I, 2); // imaginary unit squared
    printf("pow(I, 2) = %.1f%+.1fi\n", creal(z2), cimag(z2));

    double PI = acos(-1);
    double complex z3 = exp(I * PI); // Euler's formula
    printf("exp(I*PI) = %.1f%+.1fi\n", creal(z3), cimag(z3));

    double complex z4 = 1 + 2 * I, z5 = 1 - 2 * I; // conjugates
    printf("(1+2i)*(1-2i) = %.1f%+.1fi\n", creal(z4 * z5), cimag(z4 * z5));
#endif

    // designated initializers
    int numbers_array[10] = {[2] = 12, [6] = 7};
    for (int i = 0; i < 10; i++) {
        printf("numbers_array[%d] = %d\n", i, numbers_array[i]);
    }

    struct point p1 = {10, 20};
    struct point p2 = {.y = 10, .x = 20};

    printf("p1 = %i, p2 = %i\n", p1.x, p1.y);
    struct point pts[5] = {p1, [2].y = 4, [4].x = 7};
    for (int i = 0; i < 5; i++) {
        printf("pts[%d] = %i %i\n", i, pts[i].x, pts[i].y);
    }
    // constants
    const float *pf; // pf points to a constant float value same as ->  float const *pf;
    float *const pd; // pd is the constant pointer which means you cant change the address

    // restrict
    int arr[10];
    int *restrict rest_arr = (int *) malloc(sizeof(int) * 10);
    int *par = arr;
    int n;
    for (n = 0; n < 10; n++) {
        par[n] += 5;
        rest_arr[n] += 5;
        arr[n] *= 2;
        par[n] += 3;
        rest_arr[n] += 3;  // optimized by the compiler like -> rest_arr[n] += 8;
    }


    return 0;
}

void display(const arr[], size_t size) {
}

char *strcat(char *s1, const char *s2) {
}


// restrict
void f1(int n, float * restrict a1, const float * restrict a2) {
    int i;
    for (i = 0; i < n; i++) {
        a1[i] += a2[i];
    }
}