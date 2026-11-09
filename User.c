//details of S1 and s2 taken from user

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
    struct student s1, s2;
    struct student *ptr;

    // Enter Student 1 details
    printf("Enter Student 1 Details:\n");

    printf("Enter Roll No: ");
    scanf("%d", &s1.rollno);

    printf("Enter Name: ");
    scanf(" %[^\n]", s1.name);

    printf("Enter Marks: ");
    scanf("%f", &s1.marks);

    // Enter Student 2 details
    printf("\nEnter Student 2 Details:\n");

    printf("Enter Roll No: ");
    scanf("%d", &s2.rollno);

    printf("Enter Name: ");
    scanf(" %[^\n]", s2.name);

    printf("Enter Marks: ");
    scanf("%f", &s2.marks);

    // Access Student 1 using pointer
    ptr = &s1;

    printf("\n--- Student 1 Details ---\n");
    printf("Roll No: %d\n", ptr->rollno);
    printf("Name: %s\n", ptr->name);
    printf("Marks: %.2f\n", ptr->marks);

    // Access Student 2 using pointer
    ptr = &s2;

    printf("\n--- Student 2 Details ---\n");
    printf("Roll No: %d\n", ptr->rollno);
    printf("Name: %s\n", ptr->name);
    printf("Marks: %.2f\n", ptr->marks);

    return 0;
}
