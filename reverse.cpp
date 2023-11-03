#include <iostream>
#include <stdlib.h>
using namespace std;

struct List
{
    int data;
    struct List *next;
};
struct List *start = NULL;

void insert(int value)
{
    struct List *temp = (struct List *)malloc(sizeof(struct List));
    temp->data = value;
    temp->next = NULL;
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
    }
}

void reverse()
{
    struct List *curr = start;
    struct List *next = NULL;
    struct List *prev = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    start=prev;
}

void print()
{
    struct List *curr = start;
    while (curr != NULL)
    {
        cout<<curr->data<< " ";
        curr=curr->next;
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