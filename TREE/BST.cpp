#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};
// it returns root node of created tree
Node *CreateTree()
{
    cout << "Enter the value->";
    int val;
    cin >> val;
    // when ever no node is left enter -1
    if (val == -1)
    {
        return NULL; // base case
    }
    // Create new node
    Node *newNode = new Node(val);
    // left sub tree
    cout << "left of" << newNode->data << endl;
    newNode->left = CreateTree();
    // right sub tree
    cout << "right of" << newNode->data << endl;
    newNode->right = CreateTree();
    return newNode;
}
void Search(Node *root, int val)
{

    while (root != NULL)
    {
        if (root->data == val)
        {
            cout << "found->" << root->data << endl;
            return;
        }
        else if (root->data > val)
            root = root->left;
        if (root->data < val)
            root = root->right;
    }
}
Node *inOrderPredecessor(struct Node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
Node *deletion(Node *root, int val)
{

    // case1 the node is root node
    // case2 the node is leaf node
    // case3 the node is non leaf node
    Node *iPre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    // searching for the node to be deleted
    if (val < root->data)
    {
        root->left = deletion(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = deletion(root->right, val);
    }
    // deletion strategy when the node is found
    else
    {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deletion(root->left, iPre->data);
    }
    return root;
}
void Insertion(Node *root, int val)
{
    Node *prev = NULL;
    while (root != NULL)
    {
        prev = root;

        if (root->data == val)
        {
            cout << "already present";
            return;
        }
        else if (root->data > val)
            root = root->left;
        if (root->data < val)
            root = root->right;
    }
    Node *newNode = new Node(val);
    if (val < prev->data)
    {
        prev->left = newNode;
    }
    else
    {
        prev->right = newNode;
    }
}
void inorder(Node *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        cout << p->data << "->";
        inorder(p->right);
    }
}

int main()

{
    int x = 1;
    int val;

    Node *root = CreateTree();
    while (x < 5)
    {
        cin >> val;
        deletion(root, val);
        inorder(root);
        x++;
    }
}