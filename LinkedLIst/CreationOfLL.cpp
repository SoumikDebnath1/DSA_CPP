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
// Function to add item in first
Node *AddFirst(Node *head)
{
    int val;
    cout << "Enter value->";
    cin >> val;
    Node *newNode = new Node(val);
    newNode->next = head;
    return newNode;
}
// Function ot add item at the last
void AddNewNodelast(Node *head)
{
    int val;

    cout << "Enter value->";
    cin >> val;
    while (head->next != NULL)
    {

        head = head->next;
    }
    Node *newNode = new Node(val);
    head->next = newNode;
}
// function ot add item at a perticular position
void AdditionNewNode(Node *head)
{
    int val;
    int target;
    cout << "Enter value->";
    cin >> val;
    cout << "Enter after target target->";
    cin >> target;
    while (head->data != target)
    {
        head = head->next;
    }
    Node *newNode = new Node(val);
    newNode->next = head->next;
    head->next = newNode;
}
// Enter item before target
void AddNewNode(Node *head)
{
    int val;
    int target;
    cout << "Enter value->";
    cin >> val;
    cout << "Enter after target target->";
    cin >> target;
    while (head->data != target)
    {
        head = head->next;
    }
    Node *newNode = new Node(val);
    newNode->next = head->next;
    head->next = newNode;
}
// deletion

// Function to pring list
void Display(Node *head)
{

    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
}
int main()
{
    Node *head = new Node(1);
    Node *node1 = new Node(2);
    Node *node2 = new Node(1);
    Node *node3 = new Node(1);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    AddNewNode(head);
    Display(head);
}