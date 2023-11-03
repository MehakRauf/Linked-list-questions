#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
};

ListNode *head = nullptr;

ListNode *insert(int value)
{
    ListNode *temp = new ListNode;
    temp->val = value;
    temp->next = nullptr;
    return temp;
}

void hasCycle()
{
    if (head == nullptr)
        return;

    ListNode *slow = head;
    ListNode *fast = head;
    bool iscycle = false;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            iscycle = true;
            break;
        }
    }
    if (iscycle)
    {
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    
        fast->next = nullptr;
}

void print()
{
    ListNode *curr = head;
    while (curr != nullptr)
    {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    ListNode *node1 = insert(1);
    ListNode *node2 = insert(2);
    ListNode *node3 = insert(3);
    ListNode *node4 = insert(4);
    ListNode *node5 = insert(5);

    head = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4; // create a loop pointing back to node2
    node4->next = node3;
    node5->next = nullptr;

    hasCycle();
    print();

    return 0;
}