#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};
Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL)
    {
        Node *newNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = newNode;
    }
    return prev;
}
Node *CreateList()
{
    cout << "Enter list size => ";
    int Size;
    cin >> Size;
    int i = 1;
    int val;
    Node *head;
    Node *curr = head;
    while (Size != 0)
    {

        cout << "Enter Node " << i << "->";
        cin >> val;

        Node *newNode = new Node(val);
        curr->next = newNode;
        curr = newNode;

        Size--;
        i++;
    }
    head = head->next;
    return head;
}
void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
}

int main()
{
    Node *head = CreateList();
    Node *reversed = reverse(head);
    display(reversed);
}