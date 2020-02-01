#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class List
{
private:
    Node *head, *tail;

public:
    List()
    {
        head = NULL;
        tail = NULL;
    }

    Node *getHead()
    {
        return head;
    }

    void createNode(int data)
    {
        Node *temp = new Node;
        temp->data = data;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
            temp = NULL;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    // INSERTION AT START
    void insertStart(int data)
    {
        Node *temp = new Node;
        temp->data = data;
        temp->next = head;
        head = temp;
    }

    // INSERTION AT PARTICULAR POSITION
    void insertPostion(int pos, int data)
    {
        Node *previousNode = new Node;
        Node *currentNode = new Node;
        Node *temp = new Node;

        for (int i = 0; i < pos; i++)
        {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
        temp->data = data;
        previousNode->next = temp;
        temp->next = currentNode;
    }

    // DELETION
    void deleteFirstNode()
    {
        // Node *temp = new Node;
        // temp = head;
        head = head->next;
        // delete temp;
    }

    void deleteLastNode()
    {
        Node *previousNode = new Node;
        Node *currentNode = new Node;

        currentNode = head;
        while (currentNode->next != NULL)
        {
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
        tail = previousNode;
        previousNode->next = NULL;
        delete currentNode;
    }

    void printNode()
    {
        int i = 0;
        Node *temp = head;
        while (temp != NULL)
        {
            cout << "List " << i++ << endl;
            cout << "Current Addr: " << temp;
            cout << " Next Address: " << temp->next << " Data: " << temp->data << " " << endl;
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{

    List list = List();
    list.createNode(2);
    list.createNode(4);
    list.createNode(6);
    list.createNode(8);
    list.createNode(10);
    list.printNode();

    list.deleteLastNode();
    list.printNode();
    return 0;
}