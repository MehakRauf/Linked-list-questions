#include <iostream>
#include <stdlib.h>
using namespace std;

struct List
{
    int data;
    struct List *prev;
    struct List *next;
};
struct List *start = NULL;

void insert(int value)
{
    struct List *temp = (struct List *)malloc(sizeof(struct List));
    temp->data = value;
    temp->next = NULL;
    temp->prev = NULL;
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        struct List *curr = start;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = temp;
        temp->prev = curr;
    }
}
void reverse()
{
    struct List *next = NULL;
    struct List *curr = start;
    while (curr != NULL)
    {
        next = curr->prev;
        curr->prev = curr->next;
        curr->next = next;
        curr = curr->prev;
    }
    start=next->prev;
}
void print()
{
    struct List *curr = start;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}
int main()
{
    insert(4);
    insert(14);
    insert(5);
    insert(7);
    insert(10);
    insert(9);
    insert(3);
    insert(8);
    reverse();
    print();
}