#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr;

    ptr = arr;   // pointer points to first element

    printf("First element: %d\n", *ptr);
    printf("Second element: %d\n", *(ptr + 1)); 
    printf("Third element: %d\n", *(ptr + 2));
    printf("Fourth element: %d\n", *(ptr + 3));
    printf("Fifth element: %d\n", *(ptr + 4));

    return 0;
}