
#include <stdio.h>

#define UPPER 300
#define LOWER 0
#define STEP 20


float FahrToCel(float);

// Print F-C table for F = 0, 20, ..., 300
int main() {
    float fahr = LOWER;

    printf("F\tC\n");
    while (fahr <= UPPER) {
        printf("%3.0f\t%6.1f\n", fahr, FahrToCel(fahr));
        fahr = fahr + STEP;
    }

    return 0;
}

float FahrToCel(float f) {
    return (5.0/9.0)*(f - 32);
}
