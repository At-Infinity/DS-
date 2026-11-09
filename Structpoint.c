struct&pointers

#include <stdio.h>
#include <stdlib.h>
struct student {
    int rollno;
    char name[50];
    float marks;
};
int main()
{
    struct student s1 = {1, "John Doe", 85.5};
    struct student s2 = {2, "Jane Smith", 92.0};
    struct student *ptr = &s1;
    printf("Student 1:\n");
    printf("Roll No: %d\n", ptr->rollno);
    printf("Name: %s\n", ptr->name);
    printf("Marks: %.2f\n", ptr->marks);
    ptr = &s2;
    printf("\nStudent 2:\n");
    printf("Roll No: %d\n", ptr->rollno);
    printf("Name: %s\n", ptr->name);
    printf("Marks: %.2f\n", ptr->marks);
    return 0;
}
