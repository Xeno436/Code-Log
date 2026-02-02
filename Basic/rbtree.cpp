#include <iostream>
using namespace std;

enum Color
{
    RED,
    BLACK
};

struct Node
{
    int val;
    Color color;
    Node *left, *right, *parent;
    Node(int v) : val(v), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RBTree
{
public:
    RBTree() : root(nullptr) {}
    void insert(int val)
    {
        Node *node = new Node(val);
        bstInsert(node);
        fixInsert(node);
    }
    void inorder()
    {
        inorder(root);
        cout << endl;
    }

private:
    Node *root;
    void bstInsert(Node *node)
    {
        Node *y = nullptr;
        Node *x = root;
        while (x)
        {
            y = x;
            if (node->val < x->val)
                x = x->left;
            else
                x = x->right;
        }
        node->parent = y;
        if (!y)
            root = node;
        else if (node->val < y->val)
            y->left = node;
        else
            y->right = node;
    }
    void leftRotate(Node *x)
    {
        Node *y = x->right;
        x->right = y->left;
        if (y->left)
            y->left->parent = x;
        y->parent = x->parent;
        if (!x->parent)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
        y->left = x;
        x->parent = y;
    }
    void rightRotate(Node *y)
    {
        Node *x = y->left;
        y->left = x->right;
        if (x->right)
            x->right->parent = y;
        x->parent = y->parent;
        if (!y->parent)
            root = x;
        else if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;
        x->right = y;
        y->parent = x;
    }
    void fixInsert(Node *z)
    {
        while (z->parent && z->parent->color == RED)
        {
            if (z->parent == z->parent->parent->left)
            {
                Node *y = z->parent->parent->right;
                if (y && y->color == RED)
                {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }
                else
                {
                    if (z == z->parent->right)
                    {
                        z = z->parent;
                        leftRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rightRotate(z->parent->parent);
                }
            }
            else
            {
                Node *y = z->parent->parent->left;
                if (y && y->color == RED)
                {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                }
                else
                {
                    if (z == z->parent->left)
                    {
                        z = z->parent;
                        rightRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    leftRotate(z->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }
    void inorder(Node *node)
    {
        if (!node)
            return;
        inorder(node->left);
        cout << node->val << '(' << (node->color == RED ? 'R' : 'B') << ") ";
        inorder(node->right);
    }
};

int main()
{
    RBTree tree;
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &x);
        tree.insert(x);
    }
    tree.inorder();
    return 0;
}
