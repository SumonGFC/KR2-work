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

#### Simple Storage Allocator
To illustrate the above notes, write a simple storage allocator:
- Routine: `alloc(n)` returns pointer to `n` consecutive character positions,
which can be used by callers of `alloc` to store characters.
- Routine: `afree(p)` releases the store allocated by `alloc` so that it can be
used later.

The storage allocated/removed by these routines is LIFO (i.e. a stack). Note
that we *MUST* call `alloc` and `afree` like this:
```c
a = alloc(10);
b = alloc(10);
c = alloc(20);

afree(c);
afree(b);
afree(a);
```
Otherwise these routines will not really work well (UB).

```c
# define ALLOCSIZE 10000

static char allocbuff[ALLOCSIZE];
static char *allocp = allocbuff;

char *alloc(int n)
{
    // start + length - current_position == allocatable space
    if (allocbuff + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;  // return position of original pointer
    } else
        return 0;
}

void afree(char *p)
{
    if (p >= allocbuff && p <= allocbuff + ALLOCSIZE)
        allocp = p;
}
```

# SECTION 5.5: CHARACTER POINTERS AND FUNCTIONS
The length in storage of a string literal is *ONE MORE*  than the number of
characters between the double quotes.

When we pass in a string constant to a function:
```c
printf("hello, world\n"); 
```
what gets passed to it is a pointer to the beginning of the char array. It is
accessed via pointer to the first element.

Another way to store a string constant in a variable:
```c
char *pmessage;
pmessage = "now is the time";
```
This assigns to `pmessage` the pointer of the first character of the string
constant (i.e. array). There is a difference between these 2:
```c
char amessage[] = "now is the time";    // an array
char *pmessage = "now is the time";     // a pointer to an array
```
here, `amessage` is just an array, exactly big enough to hold the string
characters plus the null terminator -- the symbol `amessage` will always refer
to the same storage. `pmessage` is a pointer variable and may be changed to
point to something else, perhaps another position in the array or perhaps to
another object (char) entirely.
    - NOTE: UB if we try to modify the string array via pointer.

#### Example: strcpy
Consider these implementation:
```c
void arr_strcpy(char *src, char *dst)
{
    int i = 0;
    while ((dst[i] = src[i]) != '\0')
        i++;
}

void ptr_strcpy(char *src, char *dst)   // arguments copied into local variables
{
    // this is ridiculous. But there is an obvious overflow error in this
    // If length of dst < length of src, we get UB
    while (*dst++ = *src++)
        ;
}
```
#### Example: strcmp
```c
// return < 0 if s < t, 0 if s == t, or > 0 if s > t
int strcmp(char *s, char *t)
{
    for (; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t; // lexicographical ordering
}
```

# SECTION 5.6: POINTER ARRAYS; POINTERS TO POINTERS

Array of pointers:
```c
int *arr[]; // array of pointers to ints
```
Pointer to pointer:
```c
int **ppi;  // ppi is a pointer to a pointer to an int
```

See the 5.6 files for the code of the program outlined in this chapter.
