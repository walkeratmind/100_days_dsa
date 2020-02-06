#include <iostream>
using namespace std;

/*

     10
   /   \
  6     14
 / \    / \
5   8  11  18

*/

struct Node
{
    // int index;
    int key_value;
    Node *left;
    Node *right;
};

class BinaryTree
{
public:
    BinaryTree();
    ~BinaryTree();

    void insert(int key);
    Node *search(int key);
    void display();
    void destroy_tree();

private:
    void insert(int key, Node *leaf);
    Node *search(int key, Node *leaf);
    void destroy_tree(Node *leaf);
    void traverse(Node *leaf);

    Node *root;
};

BinaryTree ::BinaryTree()
{
    root = NULL;
    // root->index = 0;
}

BinaryTree ::~BinaryTree()
{
    destroy_tree();
}

void BinaryTree ::destroy_tree(Node *leaf)
{
    if (leaf != NULL)
    {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        delete leaf;
    }
}

void BinaryTree ::insert(int key, Node *leaf)
{

    if (key < leaf->key_value)
    {
        if (leaf->left != NULL)
        {
            insert(key, leaf->left);
        }
        else
        {
            leaf->left = new Node;
            leaf->left->key_value = key;
            // leaf->left->index = root->index++;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    }
    else if (key >= leaf->key_value)
    {
        if (leaf->right != NULL)
        {
            insert(key, leaf->right);
        }
        else
        {
            leaf->right = new Node;
            leaf->right->key_value = key;
            // leaf->right->index = root->index++;
            leaf->right->left = NULL;
            leaf->right->right = NULL;
        }
    }
}

Node *BinaryTree ::search(int key, Node *leaf)
{
    if (leaf != NULL)
    {
        if (key = leaf->key_value)
            return leaf;
        // key < leaf->key_value ? return search
        if (key < leaf->key_value)
            return search(key, leaf->left);
        else
            return search(key, leaf->right);
    }
    else
        return NULL;
}

void BinaryTree::display()
{
    int i = 0;
    traverse(root);
    cout << "end" << endl;
}

void BinaryTree ::traverse(Node *leaf)
{
    if (leaf != NULL)
    {
        cout << leaf->key_value << " ";
        if (leaf->left != NULL)
        {
            traverse(leaf->left);
        }
        if (leaf->right != NULL)
        {
            traverse(leaf->right);
        }
    }
}

void BinaryTree ::insert(int key)
{
    if (root != NULL)
    {
        insert(key, root);
    }
    else
    {
        root = new Node;
        root->key_value = key;
        // root->index = root->index++;
        root->left = NULL;
        root->right = NULL;
    }
}

Node *BinaryTree ::search(int key)
{
    return search(key, root);
}

void BinaryTree::destroy_tree()
{
    destroy_tree(root);
}

int main()
{
    BinaryTree binaryTree = BinaryTree();
    binaryTree.insert(2);
    binaryTree.insert(8);
    binaryTree.insert(3);
    binaryTree.insert(9);
    binaryTree.insert(7);

    binaryTree.display();

    // Node *searched = binaryTree.search(9);

    return 0;
}