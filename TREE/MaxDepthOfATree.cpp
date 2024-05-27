#include <iostream>
#include <queue>
#include <vector>
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
Node *createTree()
{
    cout << "Enter Data=> ";
    int data;
    cin >> data;

    Node *newNode = new Node(data);
    // Base case
    if (newNode->data == -1)
    {
        return NULL;
    }
    // for the left Node;
    newNode->left = createTree();
    // for the right Node;
    newNode->right = createTree();
}
int MaxDepth(Node *root)
{
    Node *temp = root;
    if (temp == NULL)
    {
        return 0;
    }

    int leftcall = MaxDepth(temp->left);
    int rightcall = MaxDepth(temp->right);
    int depth = max(leftcall, rightcall) + 1;
    return max(r);
}
int main()
{

    Node *root = createTree();
    cout << MaxDepth(root);
}