#include <stdio.h>
#include <string.h>
struct Student 
{
    int id;
    char name[50];
    float marks;
};
int main() 
{
    struct Student s[5];
    int i;
    for (i = 0; i < 5; i++) 
    {
        printf("Enter ID, Name, and Marks for Student %d:\n", i + 1);
        scanf("%d %s %f", &s[i].id, s[i].name, &s[i].marks);
    }
    printf("\nStudent Database:\n");
    for (i = 0; i < 5; i++) 
    {
        printf("ID: %d, Name: %s, Marks: %.2f\n", s[i].id, s[i].name, s[i].marks);
    }
    return 0;
}
