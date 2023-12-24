
#include <stdio.h>

#define UPPER 300
#define LOWER 0
#define STEP 20


// Print F-C table for F = 0, 20, ..., 300
int main() {
    float fahr = LOWER;
    float cel;
    printf("Fahr\tCel\n");
    while (fahr <= UPPER) {
        cel = (5.0/9.0)*(fahr - 32); //need to put 5.0 and 9.0 to specify floating point division
        printf("%3.0f\t%6.1f\n", fahr, cel); 
        // %6.1f means at least 6 characters wide, and 1 digit to the right of the decimal point
        fahr = fahr + STEP;
    }
    printf("______________\n\n");

    //Now, print celsius to fahrenheit table
    printf("%3s\t%6s\n", "C", "F");
    for (cel = LOWER; cel <= UPPER; cel = cel + STEP) {
        fahr = (9.0/5.0)*cel + 32;
        printf("%3.0f\t%6.1f\n", cel, fahr);
    }


    return 0;
}