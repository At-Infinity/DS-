DMA

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i, *ptr;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    ptr = (int*)malloc(n * sizeof(int));
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    } else {
        printf("Enter the elements:\n");
        for (i = 0; i < n; ++i) {
            scanf("%d", ptr + i);
        }
        printf("The elements are: ");
        for (i = 0; i < n; ++i) {
            printf("\n %d", *(ptr + i));
        }
        printf("\n");
        free(ptr);
    }
}
