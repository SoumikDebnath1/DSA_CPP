#include <iostream>
using namespace std;
class Node
{
    int data;
    Node *next;
    Node(){
        this->next = NULL :
    } Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};

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
