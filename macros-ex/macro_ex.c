//
// Created by moezgen on 12/17/24.
//
#include <stdio.h>

#define PRNT(x) \
    printf("x = %d\n", x);

#define SQ(x) x*x

#define PI 3.14159265358979323846
#define CIRCLE_AREA(x) ((x) * (x) * PI)

#define WARN(...) fprintf(stderr, __VA_ARGS__)

double circle_area(double x) {
    printf( "%s is called \n", __func__ );
    return x * x * PI;
}

int main(void) {
    PRNT(2);
    PRNT(SQ(3));
    int area = CIRCLE_AREA(4);
    printf("Area = %d\n", area);
    int area2 = circle_area(4);
    printf("Area = %d\n", area2);
    WARN("%s : test warning message", "example program");
    printf("File is %s line is %d\n", __FILE__, __LINE__);
    printf("The program last compiled at %s on %s\n", __TIME__, __DATE__);
    return 0;
}
