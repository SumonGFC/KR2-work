
#include <stdio.h>

int main() {    

    // chars
    printf("sizeof char: %lu bytes \n", sizeof(char));
    printf("sizeof signed char: %lu bytes \n", sizeof(signed char));
    printf("sizeof unsigned char: %lu bytes\n", sizeof(unsigned char));
    // shorts
    printf("sizeof short: %lu bytes\n",sizeof(short));
    printf("sizeof unsigned short: %lu bytes\n", sizeof(unsigned short));
    // ints
    printf("sizeof int: %lu bytes\n",sizeof(int));
    printf("sizeof unsigned int: %lu bytes\n",sizeof(unsigned int));
    //longs
    printf("sizeof long: %lu bytes\n",sizeof(long));
    printf("sizeof unsigned long: %lu bytes\n", sizeof(unsigned long));
    printf("sizeof long long: %lu bytes\n", sizeof(long long));
    printf("sizeof unsigned long long: %lu bytes\n", sizeof(unsigned long long));
    //floats
    printf("sizeof float: %lu bytes\n", sizeof(float));
    printf("sizeof doube: %lu bytes\n", sizeof(double));
    printf("sizeof long double: %lu bytes\n", sizeof(long double));

    return 0;
}
