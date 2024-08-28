// Compile: gcc 4.10_recursion.c && ./a.out

#include <stdio.h>
#include <stdlib.h>

void swap(int arr[], int i, int j);
void my_qsort(int arr[], int left, int right);

int main(void)
{
        int arr[10];
        
        srand(0);
        printf("Array: ");
        for (int i = 0; i < 10; ++i) {
                arr[i] = (rand() % 29);
                printf("%d, ",arr[i]);

        }
        printf("\n");

        my_qsort(arr, 0, 9);
        
        printf("Sorted: ");
        for (int i = 0; i < 10; ++i)
                printf("%d, ", arr[i]);
        printf("\n");
        return 0;
}

void my_qsort(int arr[], int left, int right)
{
        int i, last;
        void swap(int[], int, int);

        // base case: do nothing
        if (left >= right)
                return;
        // choose middle element to be pivot; place it in 0th position
        swap(arr, left, (left + right) / 2);
        last = left;
        // sort
        for (i = left + 1; i <= right; ++i)
                if (arr[i] < arr[left])
                        swap(arr, ++last, i);
        // place pivot at its correct position
        swap(arr, left, last);
        my_qsort(arr, left, last - 1);
        my_qsort(arr, last + 1, right);
}

void swap(int arr[], int i, int j)
{
        int temp;

        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
}
