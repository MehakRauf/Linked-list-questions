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
void delete_occurences(int val)
{
    while (start != NULL && start->data == val)
    {
        struct List *curr = start;
        start = start->next;
        free(curr);
    }
    struct List *curr = start;
    struct List *prev = NULL;
    while (curr != NULL)
    {
        if (curr->data == val)
        {
            struct List *temp = curr;
            prev->next = curr->next;
            free(temp);
        }
        prev = curr;
        curr = curr->next;
    }
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
    insert(2);
    insert(2);
    insert(5);
    insert(49);
    insert(2);
    insert(9);
    insert(40);
    insert(8);
    delete_occurences(2);
    print();
}