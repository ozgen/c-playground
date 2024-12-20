//
// Created by moezgen on 12/6/24.
//
#include <math.h>
#include <stdio.h>
#include <stdarg.h>

double average(double n, ...);

double sample_stddev(double n, ...);

int main(void) {
    // Use 0.0 as the sentinel value to indicate the end of the arguments
    double result = average(16.0, 2.0, 3.0, 4.0, 5.0);
    printf("%f\n", result);

    double stddev = sample_stddev(4.0, 2.0, 3.0, 4.0, 5.0);
    printf("%f\n", stddev);
    return 0;
}

double average(double n, ...) {
    va_list ap;
    double sum = 0.0;
    double value = 0.0;
    int count = 0;

    va_start(ap, n);

    // Include the first argument in the sum
    sum += n;
    count++;

    // Loop through the remaining arguments until 0.0 is encountered
    while ((value = va_arg(ap, double)) != 0.0) {
        sum += value;
        count++;
    }

    va_end(ap);
    return sum / count;
}

double sample_stddev(double n, ...) {
    va_list ap;
    double sum = 0.0;
    double value = 0.0;

    // First pass: calculate the mean
    va_start(ap, n);
    for (int i = 0; i < n; i++) {
        sum += va_arg(ap, double);
    }
    double mean = sum / n;
    va_end(ap);

    // Second pass: calculate the sum of squared differences
    double sum_sq_diff = 0.0;
    va_start(ap, n);
    for (int i = 0; i < n; i++) {
        value = va_arg(ap, double);
        sum_sq_diff += (value - mean) * (value - mean);
    }
    va_end(ap);

    // Return the standard deviation
    return sqrt(sum_sq_diff / n);
}

