#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Passenger 
{
    int bookingID;
    char name[50];
    char coach[5];
    struct Passenger* next;
};
struct Passenger* head = NULL;
void addPassenger(int id, char* name, char* coach) 
{
    struct Passenger* newPassenger = (struct Passenger*)malloc(sizeof(struct Passenger));
    newPassenger->bookingID = id;
    strcpy(newPassenger->name, name);
    strcpy(newPassenger->coach, coach);
    newPassenger->next = head;
    head = newPassenger;
}
void removePassenger(int id) 
{
    struct Passenger* temp = head;
    struct Passenger* prev = NULL;
    if (temp != NULL && temp->bookingID == id) 
    {
        head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->bookingID != id) 
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}
void displayPassengersByCoach(char* coach) 
{
    struct Passenger* temp = head;
    while (temp != NULL) 
    {
        if (strcmp(temp->coach, coach) == 0) 
        {
            printf("ID: %d, Name: %s\n", temp->bookingID, temp->name);
        }
        temp = temp->next;
    }
}
int countPassengers()
{
    struct Passenger* temp = head;
    int count = 0;
    while (temp != NULL) 
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() 
{
    clrscr();
    addPassenger(1, "Kumar", "A1");
    addPassenger(2, "Sanjay", "B1");
    addPassenger(3, "Ram", "A1");
    printf("Total passengers: %d\n", countPassengers());
    printf("Passengers in coach A1:\n");
    displayPassengersByCoach("A1");
    removePassenger(2);
    printf("Total passengers after removal: %d\n", countPassengers());
    getch();
    return 0;
}