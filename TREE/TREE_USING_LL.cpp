#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// Create tree data type using LL
struct node
{
    int data;
    struct node *LC;
    struct node *RC;
};
typedef struct node node;
/****************************************************************************/
node *root = NULL;
int count = 1;
/****************************************************************************/
// INSERTION
node *insert(node *p, long digit) // called a node type function
{

    if (p == NULL) // if the root node is not null then
    {

        p = (node *)malloc(sizeof(node));
        p->data = digit; // data will be inserted in the root
        count++;
        p->RC = p->LC = NULL; // and LC and RL will be pointing to null
    }
    else if (count % 2 == 0)          // if root have data
        p->LC = insert(p->LC, digit); // data will be in left node  first node

    else                              // if data is already in first node  then  it will point to the  second node
        p->RC = insert(p->RC, digit); // which is right node
    return p;
}
/***********************************preorder*****************************************/
void Preorder(node *p)
{
    if (p != NULL)
    {
        cout << p->data << "->";
        Preorder(p->LC);
        Preorder(p->RC);
    }
}

/*************************************Inorder****************************************/
void inorder(node *p)
{
    if (p != NULL)
    {
        inorder(p->LC);
        cout << p->data << "->";
        inorder(p->RC);
    }
}
// Iterative function for inorder tree traversal
void inOrder(node *p)
{
    stack<node *> s;
    node *curr = p;

    while (curr != NULL || s.empty() == false)
    {

        // Reach the left most Node of the
        // curr Node
        while (curr != NULL)
        {

            // Place pointer to a tree node on
            // the stack before traversing
            // the node's left subtree
            s.push(curr);
            curr = curr->LC;
        }

        // Current must be NULL at this point
        curr = s.top();
        s.pop();

        cout << curr->data << " ";

        // we have visited the node and its
        // left subtree.  Now, it's right
        // subtree's turn
        curr = curr->RC;
    }
}
void inOrder2(node *p)
{
    stack<node *> s;
    node *curr = p;

    while (true)
    {
        if (curr != NULL)
        {

            s.push(curr);
            curr = curr->LC;
        }
        else
        {
            if (s.empty() == true)
                break;
            curr = s.top();
            s.pop();
            cout << curr->data << " ";
            curr = curr->RC;
        }
    }
}
/***********************************Post order******************************************/
void Postorder(node *p)
{
    if (p != NULL)

    {
        Postorder(p->LC);
        Postorder(p->RC);
        cout << p->data << "->";
    }
}
void postOrder(node *root)
{

    if (root == NULL)
        return;
    stack<node *> S;
    S.push(root);
    node *prev = NULL;
    while (!S.empty())
    {
        node *current = S.top();
        /* go down the tree in search of a leaf an if so
           process it and pop stack otherwise move down */
        if (prev == NULL || prev->LC == current || prev->RC == current)
        {
            if (current->LC)
                S.push(current->LC);
            else if (current->RC)
                S.push(current->RC);
            else
            {
                S.pop();
                cout << current->data << "->";
            }
            /* go up the tree from left node, if the child
               is right push it onto stack otherwise process
               parent and pop stack */
        }

        else if (current->LC == prev)
        {
            if (current->RC)
                S.push(current->RC);
            else
            {
                S.pop();
                cout << current->data << "->";
            }

            /* go up the tree from right node and after
            coming back from right node process parent and
            pop stack */
        }
        else if (current->RC == prev)
        {
            S.pop();
            cout << current->data << "->";
        }
        prev = current;
    }
}
/****************************************************************************/
int Select()
{
    int selection;
    do
    {
        puts("\nEnter 1: Insert a node in the BT");
        puts("Enter 2: Diplay BT preorder");
        puts("Enter 3: inorder node in the BT");
        puts("Enter 4: post order node in the BT");
        puts("Enter 5: End");
        puts("Enter Your Choice");
        cin >> selection;
        if ((selection < 1) || (selection > 5))
        {
            puts("Wrong Choice:Try again");
        }
    } while ((selection < 1) || (selection > 5));
    return selection;
}

int main()
{
    int choice;
    long digit;
    do
    {

        choice = Select();
        switch (choice)
        {

        case 1:
            puts("integer: to quit enter 0");
            cin >> digit;
            while (digit != 0)
            {
                root = insert(root, digit);
                cin >> digit;
            }
            continue;
        case 2:
            puts("\n Preorder traversing TREE");
            Preorder(root);
            continue;
        case 3:
            puts("\n inorder traversing TREE");
            inOrder(root);
            continue;
        case 4:
            puts("\n Postorder traversing TREE");
            postOrder(root);
            continue;
        case 5:
            puts("\n END ");
            exit(0);
        }
    } while (choice != 5);
}
