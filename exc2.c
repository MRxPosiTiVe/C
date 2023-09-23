#include <stdio.h>

int main() {

    float a, b, c, x;

    printf("Write a, b, c: ");
    scanf("%f %f %f", &a, &b, &c);

    x = (c - b)/a;

    printf("Answer %f\n", x);

    return 0;
}