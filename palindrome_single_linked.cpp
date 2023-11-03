#include <iostream>
#include <stdlib.h>
#include <stack>
using namespace std;

struct List
{
    struct List *next;
    int data;
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
bool palindrome()
{
    stack<int> s;
    List *curr = start;
    while (curr != NULL)
    {
        s.push(curr->data);
        curr = curr->next;
    }
    curr = start;
    while (curr != NULL)
    {
        int i = s.top();
        s.pop();
        if (curr->data != i)
        {
            return false;
        }
        curr=curr->next;
    }
    return true;
}
void print()
{
    struct List *curr = start;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
int main()
{
    insert(9);
    insert(2);
    insert(1);

    print();
    cout<<palindrome();
}