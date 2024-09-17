#include <stdio.h>
#include<conio.h>
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main() 
{
    int x, y;
    clrscr();
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);
    printf("Before Swap: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After Swap: x = %d, y = %d\n", x, y);
    getch();
    return 0;
}
