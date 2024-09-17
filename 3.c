#include <stdio.h>
#define MAX 100

int maze[10][10], visited[10][10];
int rows, cols;
typedef struct 
{ int x, y;} Stack;
Stack stack[MAX];
int top = -1;
void push(int x, int y) 
{
    if (top == MAX - 1) 
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top].x = x;
    stack[top].y = y;
}
Stack pop() {
    Stack temp = {-1, -1};
    if (top == -1) {
        printf("Stack Underflow\n");
        return temp;
    }
    return stack[top--];
}
int isEmpty() {
    return top == -1;
}
void printPath() {
    printf("Path:\n");
    for (int i = 0; i <= top; i++) {
        printf("(%d, %d) -> ", stack[i].x, stack[i].y);
    }
    printf("Exit\n");
}
int isValid(int x, int y) {
    return x >= 0 && x < rows && y >= 0 && y < cols && maze[x][y] == 0 && !visited[x][y];
}
int solveMaze(int startX, int startY, int exitX, int exitY) {
    push(startX, startY);
    visited[startX][startY] = 1;
    while (!isEmpty()) {
        Stack current = stack[top];
        int x = current.x;
        int y = current.y;
        if (x == exitX && y == exitY) {
            printPath();
            return 1;
        }
        if (isValid(x + 1, y)) {  
            push(x + 1, y);
            visited[x + 1][y] = 1;
        } else if (isValid(x - 1, y)) {  
            push(x - 1, y);
            visited[x - 1][y] = 1;
        } else if (isValid(x, y + 1)) {  
            push(x, y + 1);
            visited[x][y + 1] = 1;
        } else if (isValid(x, y - 1)) { 
            push(x, y - 1);
            visited[x][y - 1] = 1;
        } else {
            pop();
        }
    }
    return 0;
}
int main() 
{
    clrscr();
    printf("Enter the number of rows and columns in the maze: ");
    scanf("%d %d", &rows, &cols);
    printf("Enter the maze (0 for open path, 1 for wall):\n");
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            scanf("%d", &maze[i][j]);
            visited[i][j] = 0;  
        }
    }
    int startX, startY, exitX, exitY;
    printf("Enter the starting point (row and column): ");
    scanf("%d %d", &startX, &startY);
    printf("Enter the exit point (row and column): ");
    scanf("%d %d", &exitX, &exitY);
    if (solveMaze(startX, startY, exitX, exitY)) {
        printf("Maze solved!\n");
    } else {
        printf("No solution exists for the maze.\n");
    }
    getch();
    return 0;
}
