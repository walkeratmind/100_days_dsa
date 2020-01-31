#include <iostream>

using namespace std;

class Node
{
private:
    int data;
    Node *next;

public:
    Node() {}
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }

    int getData()
    {
        return data;
    }

    void setData(int data)
    {
        this->data = data;
    }

    Node *getNext()
    {
        return next;
    }

    void setNext(Node *next)
    {
        this->next = next;
    }
};

void printNode(Node *node)
{
    int i = 0;
    while (node != NULL)
    {
        cout << "List " << i++ << endl;
        cout << "Current Addr: " << node;
        cout << " Next Address: " << node->getNext() << " Data: " << node->getData() << " " << endl;
        node = node->getNext();
    }
    cout << endl;
}

int main()
{

    // allocate these nodes so they gets to store in memory
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();
    Node *fourth = new Node();

    // head = new Node(2, second);
    // second = new Node(4, third);
    // Node *fourth = new Node(8, NULL);
    // third = new Node(6, fourth);
    head->setData(2);
    head->setNext(second);

    second->setData(4);
    second->setNext(third);

    third->setData(6);
    third->setNext(fourth);

    fourth->setData(8);
    fourth->setNext(NULL);

    printNode(head);

    // cout << "head: " << head->getNext() << "\nsecond: " << second;

    return 0;
}