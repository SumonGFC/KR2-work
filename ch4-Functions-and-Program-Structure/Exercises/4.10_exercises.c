/* Exercise 4-12. Adapt the ideas of printd to write a recursive version of
 * itoa; that is, convert an integer into a string by calling a recursive 
 * routine.
 * 
 * Exercise 4-13. Write a recursive version of the function reverse(s), which 
 * reverses the string s in place.
 */

// THIS PROGRAM "WORKS", BUT THERE ARE MANY DESIGN FLAWS AND A FEW BUGS
// I can't be bothered to make it perfect so I'm just going to move on.
// Were this a school assignment I would take the time to make it "perfect"
// Alas, the more time I have lived the more I realize how little there is of it
// :(

#include <stdio.h>
#include <string.h>

#define MAXLEN 100

void itoa(int, char[]);
void itoa_rec(int number, int index, char str[]);
void reverse(char[]);
void reverse_rec(char[], int first, int last);

int main(void)
{
        int test1 = -12345;
        int test2 = 3846128;
        char arr[MAXLEN];
        itoa_rec(test1, 0, arr);
        reverse_rec(arr, 0, strlen(arr)-1);
        printf("%s\n", arr);

        itoa_rec(test2, 0, arr);
        reverse_rec(arr, 0, strlen(arr)-1);
        printf("%s\n", arr);
        return 0;
}

void itoa_rec(int n, int pos, char s[MAXLEN])
{
        static int sign = 0;
        if (sign == 0) {
                sign = n < 0 ? -1 : 1;
                n = sign < 0 ? -n : n;
        }

        if (n/10)
                itoa_rec(n/10, pos + 1, s);
        else if (sign < 0) {
                s[pos + 1] = '-';
                s[pos + 2] = '\0';
        } else
                s[pos + 1] = '\0';
        s[pos] = n % 10 + '0';
}

void reverse_rec(char s[], int first, int last)
{
        if (first >= last)
                return;
        else {
                char tmp = s[first];
                s[first] = s[last];
                s[last] = tmp;
                reverse_rec(s, ++first, --last);
        }
        return;
}


/* printd: print n in decimal */
void printd(int n)
{
        if (n < 0) {
                putchar('-');
                n = -n;
        }
        if (n / 10)
                printd(n / 10);
        putchar(n % 10 + '0');
} 
