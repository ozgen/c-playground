//
// Created by moezgen on 12/5/24.
//
#include <stdio.h>

int main(){

    //goto example
    const int max_input = 5;
    int t = 0;
    double num, average, sum = 0.0;

    for (t = 1; t <= max_input; ++t) {
        printf("%d. Enter a number: ", t);
        scanf("%lf", &num);
        if (num < 0.0) {
            goto calculate;
        }
        sum += num;
    }

    calculate:
        if (t == 1) {
            printf("No numbers were entered.\n");
        } else {
            average = sum / (t - 1);
            printf("Average = %.2f\n", average);
            printf("Sum = %.2f\n", sum);
        }

    // end goto example
}