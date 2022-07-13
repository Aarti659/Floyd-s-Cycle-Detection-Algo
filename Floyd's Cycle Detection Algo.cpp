#include <iostream>
#include <unordered_set>
using namespace std;
 struct Node
{    int Data;
    Node* next;
};
 void push(Node*& headRef, int Data)
{
    Node* newNode = new Node;

    newNode->Data = Data;
    newNode->next = headRef;
    headRef = newNode;
}
 bool det_Cyc(Node* head)
{
    Node *slow = head, *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;

        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

int main()
{

    int keys[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(keys) / sizeof(keys[0]);

    Node* head = nullptr;
    for (int i = n - 1; i >= 0; i--) {
        push(head, keys[i]);
    }
     head->next->next->next->next->next = head->next->next;

    if (det_Cyc(head)) {
        cout << "Cycle Found";
    }
    else {
        cout << "No Cycle Found";
    }

    return 0;
}
