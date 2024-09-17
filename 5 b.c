#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;
void enqueue(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;    
    if (rear == NULL) 
    {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}
int dequeue() 
{
    if (front == NULL) 
    {
        printf("Queue Underflow\n");
        return -1;
    }
    struct Node* temp = front;
    int data = front->data;
    front = front->next;    
    if (front == NULL) 
    {
        rear = NULL;
    }
    free(temp);
    return data;
}
int isEmpty() 
{
    return front == NULL;
}
void display() 
{
    if (isEmpty()) 
    {
        printf("Queue is empty\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue: ");
    while (temp != NULL) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() 
{
    clrscr();
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();    
    dequeue();
    display();
    getch();
    return 0;
}
