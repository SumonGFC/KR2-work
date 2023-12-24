
#include <stdio.h>

int main() {    

    // chars
    printf("sizeof char: %lu\n bytes", sizeof(char));
    printf("sizeof signed char: %lu\n bytes", sizeof(signed char));
    printf("sizeof unsigned char: %lu\n bytes", sizeof(unsigned char));
    // shorts
    printf("sizeof short: %lu\n bytes",sizeof(short));
    printf("sizeof unsigned short: %lu\n bytes", sizeof(unsigned short));
    // ints
    printf("sizeof int: %lu\n bytes",sizeof(int));
    printf("sizeof unsigned int: %lu\n bytes",sizeof(unsigned int));
    //longs
    printf("sizeof long: %lu\n bytes",sizeof(long));
    printf("sizeof unsigned long: %lu\n bytes", sizeof(unsigned long));
    printf("sizeof long long: %lu\n bytes", sizeof(long long));
    printf("sizeof unsigned long long: %lu\n bytes", sizeof(unsigned long long));
    //floats
    printf("sizeof float: %lu\n bytes", sizeof(float));
    printf("sizeof doube: %lu\n bytes", sizeof(double));
    printf("sizeof long double: %lu\n bytes", sizeof(long double));

    return 0;
}