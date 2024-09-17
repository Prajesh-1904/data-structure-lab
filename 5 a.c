#include <stdio.h>
#define MAX 100
int queue[MAX];
int front = -1, rear = -1;
void enqueue(int data) 
{
    if (rear == MAX - 1) 
    {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) 
    {
        front = 0;
    }
    queue[++rear] = data;
}
int dequeue() 
{
    if (front == -1 || front > rear) 
    {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++];
}
int isEmpty() 
{
    return front == -1 || front > rear;
}
void display() 
{
    if (isEmpty()) 
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = front; i <= rear; i++) 
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
int main() 
{
    clrrscr();
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    dequeue();
    display();
    getch();n
    return 0;
}
