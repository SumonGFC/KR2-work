#include <stdio.h>
#include <string.h>

/************************************************************************MAIN*/
#define MAXLINES 5000

char *lineptr[MAXLINES]; // store pointers to input lines

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int main(void)
{
    int nlines;

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        //qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort.\n");
        return 1;
    }
}

/********************************************************************READLINES*/
#define MAXLEN 1000

int my_getline(char *, int);
char *alloc(int);

// read input lines into line pointer; return num of lines
int readlines(char *lineptr[], int maxlines)
{
        int len, line_cnt;
        char *p, buff[MAXLEN];

        line_cnt = 0;
        while ((len = my_getline(buff, MAXLEN)) > 0) {
                if (line_cnt >= maxlines || (p = alloc(len)) == NULL) {
                        return -1;
                }
                else {
                        buff[len - 1] = '\0';   // remove \n
                        strcpy(p, buff);
                        lineptr[line_cnt++] = p;
                }
        }
        return line_cnt;
}

// returns number of chars read, stores result in buff
int my_getline(char *buff, int size)
{
        if (size <= 1) {
                printf("Error: my_getline(): not enough space\n");
                return -1;
        }
        int i, c;
        for (i = 0; i < size - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
                *(buff + i) = c;
        if (c == '\n')
                buff[i++] = c;
        buff[i] = '\0';
        return i;
}

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
        return NULL;
}

/*******************************************************************WRITELINES*/

void writelines(char *lineptr[], int nlines)
{
        int i;

        for (i = 0; i < nlines; i++)
                printf("%s\n", lineptr[i]);
}
