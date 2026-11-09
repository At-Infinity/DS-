Combined (Struct, pointers and malloc)


#include <stdio.h>
#include <stdlib.h>

struct student
{
    int rollno;
    char name[50];
    float marks;
};

int main()
{
    int n, i;
    struct student *ptr;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Dynamic memory allocation
    ptr = (struct student *)malloc(n * sizeof(struct student));

    if (ptr == NULL)
    {
        printf("Memory not allocated.\n");
        exit(0);
    }

    // Enter student details
    for (i = 0; i < n; i++)
    {
        printf("\nEnter details of Student %d\n", i + 1);

        printf("Enter Roll Number: ");
        scanf("%d", &(ptr + i)->rollno);

        printf("Enter Name: ");
        scanf(" %[^\n]", (ptr + i)->name);

        printf("Enter Marks: ");
        scanf("%f", &(ptr + i)->marks);
    }

    // Display student details
    printf("\n--- STUDENT DETAILS ---\n");

    for (i = 0; i < n; i++)
    {
        printf("\nStudent %d\n", i + 1);
        printf("Roll Number: %d\n", (ptr + i)->rollno);
        printf("Name: %s\n", (ptr + i)->name);
        printf("Marks: %.2f\n", (ptr + i)->marks);
    }

    // Free allocated memory
    free(ptr);

    return 0;
}
