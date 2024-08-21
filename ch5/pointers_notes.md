This is just a collection of notes on pointers from chapter 5.

# SECTION 5.1: POINTERS AND ADDRESSES
```c
int section_5_1(void)
{
        int x = 1;
        // POINTER DECLARATIONS ARE A MNEMONIC:
        int *ip;
        // this indicates that the SYMBOL, "*ip", is an int. This is similar to
        // function declarations:
        int func(void);
        // where the return type "int" is really saying that the symbol "func"
        // should be an int where it is referenced

        // VALID OPERANDS OF DEREFERENCE OPERATOR:
        // The & operator can only be applied to objects in memory (variables,
        // array elements, other pointers). It CANNOT be applied to expressions,
        // constants, or register variables.
        ip = &x;

        // REFERENCE AND DEREFERENCE, & AND *, BIND MORE TIGHTLY THAN ARITHMETIC
        // OPERATORS:
        int y = *ip + 1;        // *ip is evaluated before addition
        *ip += 1;               // dereference, THEN increment
        ++*ip;                  // dereference, THEN increment

        (*ip)++;                // parentheses are necessary here: without them,
                                // this expression would increment ip then
                                // dereference it because unary ops associate
                                // right to left (i.e. *(ip++) )

        // POINTERS ARE VARIABLES:
        int *iq;                // can assign pointers as values -- values are
        iq = ip;                // virtual addresses
                                

        return 0;
}
```

# SECTION 5.2: POINTERS AND FUNCTION ARGUMENTS
```c
void bad_swap(int x, int y)             // WRONG!
{
        int tmp = x;
        x = y;
        y = tmp;
}

void good_swap(int *x, int *y)          // Correct: call as good_swap(&x, &y)
{
        // pass in references to x and y, then interchange the values stored at
        // those references
        int tmp = *x;
        *x = *y;
        *y = tmp;
}
```

C is pass by value (except for arrays which are essentially pointers).
We can enable a function to access and change objects in the scope of the
caller. 
EXAMPLE: getint()
```c
#define SIZE 100

int getint(int *);

void section_5_2_getint_example(void)
{
        int n, array[SIZE], getint(int *);
        for (n = 0; n < SIZE && (getint(&array[n]) != EOF); n++)
                printf("array[%d] = %d\n", n, array[n]);
}

int getch(void);
void ungetch(int);

int getint(int *s)
{
        int c, sign;

        while (isspace(c = getch()))
                ;
        if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
                ungetch(c);
                return 0;
        }

        sign = (c == '-') ? -1 : 1;
        if (c == '+' || c == '-')
                c = getch();
        for (*s = 0; isdigit(c); c = getch())
                *s = 10 * (*s) + (c - '0');
        *s *= sign;
        if (c != EOF)
                ungetch(c);
        return c;
}

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void) /* get a (possibly pushed-back) character */
{
        return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /* push character back on input */
{
        if (bufp >= BUFSIZE)
                printf("ungetch: too many characters\n");
        else
                buf[bufp++] = c;
} 
```
# SECTION: 5.3 POINTERS AND ARRAYS
```c
void section_5_3(void)
{
        int arr[10];
        int *pa;

        // these are equivalent:
        pa = arr;
        pa = &arr[0];
        pa = (arr + 0);

        if (arr[3] == *(pa + 3) &&
                        pa == arr && 
                        *pa == *arr && 
                        pa[1] == arr[1] &&
                        *(pa + 2) == *(arr + 2) && 
                        (pa + 4) == &arr[4]) {
                printf("This will print!\n");
        }

        // NOTE: difference between a pointer and array name is that a pointer
        // is a VARIABLE -- the array name is not. This means that these
        // statements are legal:
        pa = &arr[5];
        pa++;

        // but these statements are not legal:
        // arr = pa;
        // arr++;
}
```

When you pass an array name to a function, what gets passed is the location
of the 0th element -- pass by value where the value is a reference. Example:
```c
int my_strlen(char *s)
{
        int n;
        // s is a local variable! can modify it as we please.
        for (n = 0; *s != '\0'; ++n, ++s)
                ;
        return n;
}
```
We can call `my_strlen`like this:
```c
my_strlen("Hello, world!");  // string constant
my_strlen(arr);              // name of an array ( char array[] )
my_strlen(ptr);              // pointer ( char *ptr)
my_strlen(&var);             // address of a variable ( char var = array[0] )
my_strlen(&arr[2]);          // length of subarray from 3rd index
my_strlen(a + 2);            // same as above
```
NEGATIVE INDICES
If you are SURE that an element exists in an array, negative indices are
allowed. Usually this happens when a pointer variable is pointing to an
object that is NOT the first element of an array.

# SECTION 5.4: ADDRESS ARITHMETIC
C standard guarantees that 0x0 is never a valid address for data
    - a return value of 0 can be used to indicate an abnormal event.

Pointers and Integers are NOT interchangeable. 0x0 is the sole exception. The 
constant 0 may be assigned or compared with a pointer. The symbolic constant
`NULL` is often used in place of 0 when assigning the value `0` to a pointer
variable, as a mnemonic -- use `NULL` to indicate a pointer is pointing to `0`,
i.e. nothing.

Pointers may be compared under certain conditions:
- If `p` and `q` point to members of the same array, then we can compare
them via ==, <=, !=, etc.

- can compare any pointer with 0

- UB: comparison with pointers that point to elements of DIFFERENT arrays
    - Exception: the address of the first element past the end of an array
    can be used in pointer arithmetic.

- pointers may be added or subtracted. if `p` is a pointer to an array,
then `p + n` will point to the nth object in the array. `n` will be
scaled according to the size/type of the object that `p` points to.

- Pointer subtraction is also valid. If `p` and `q` point to elements of the
same array with `q` > `p`, then `q - p + 1` gives us the number of objects
between `q` and `p`.

With the last point, we can wrie another version of `strlen`:
```c
int strlen(char *s)
{
        char *p = s;
        for (; *p != '\0'; ++p)
                ;
        return p - s;
}
```
Note that the number of characters in the string may be too large to store in
an `int`. The header `<stddef.h>` defines a type `ptrdiff_t` that is large
enought to store the signed difference of two pointer values.

To be cautious, use `size_t` for the return value of `strlen`, to match the
standard library version. `size_t` is the *unsigned integer type* that is 
returned by the `sizeof()` operator.

Pointer arithmetic is consistent:
```c
short arr_i[];
double arr_f[];
short *pi = &arr_i[0];
double *pf = & arr_f[0];

pi + 5; // refers to 5th element of arr_i
pf + 5  // refers to the 5th element of arr_f
```
all pointer manipulations take into account the size of the object that the
pointer points to.

TL;DR

LEGAL POINTER OPS:
- assignment of pointers to pointer vars of the same type
- adding/subtracting an pointers and ints
- comparing/subtracting two pointers that point to objects in same array
- assignment of one pointer to a `void *`
- case pointer to another type

ILLEGAL OPS:
- add two pointers
- multiply, divide, shift, or mask 2 pointers
- add `float` or `double` to a pointer
- assign a pointer of one type to a pointer of another type
    - except to `void *` or casting before assignment


