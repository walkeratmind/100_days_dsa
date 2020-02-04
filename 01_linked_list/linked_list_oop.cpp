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

    // INSERTION
    void addFirst(int data)
    {
        Node *temp = new Node;
        temp->data = data;
        temp->next = head;
        head = temp;
    }

    void addLast(int data)
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

    void insertPostion(int pos, int data)
    {
        Node *previousNode = new Node;
        Node *currentNode = head;
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
    void deleteFirst()
    {
        // Node *temp = new Node;
        // temp = head;
        head = head->next;
        // delete temp;
    }

    void deleteLast()
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

    int indexOf(int data)
    {
        Node *currentNode = new Node;

        currentNode = head;

        int index = 0;
        while (currentNode != NULL)
        {
            // check for first
            if (currentNode->data == data)
            {
                return index;
            }
            index++;
            currentNode = currentNode->next;
        }
        return -1;
    }

    bool contains(int data)
    {
        // Node *currentNode = head;

        // while (currentNode != NULL)
        // {
        //     if (currentNode->data == data)
        //     {
        //         return true;
        //     }
        //     currentNode = currentNode->next;
        // }
        // return false;
        return indexOf(data) != -1;
    }
    inline bool isEquals(int val1, int val2)
    {
        return val1 == val2 ? true : false;
    }

    int size()
    {
        Node *currentNode = head;

        int count = 0;
        while (currentNode != NULL)
        {
            count++;
            currentNode = currentNode->next;
        }
        return count;
    }

    int *toArray()
    {
        Node *currentNode = head;

        static int arr[100];
        int i = 0;
        while (currentNode != NULL)
        {
            arr[i] = currentNode->data;
            currentNode = currentNode->next;
            i++;
        }

        return arr;
    }

    void reverse()
    {
        Node *previous = head;
        Node *current = head->next;
        Node *next = new Node;

        cout << "Reversing..." << endl;

        while (current != NULL)
        {
            cout << "previous: " << previous->data << endl;
            Node *next = current->next;
            cout << "next: " << next->data << endl;

            current->next = previous;

            cout << "current: " << current->data << endl;
            previous = current;
            current = next;

            // temp = current;
            // temp->next = previous;
            // cout << "temp: " << temp->data << endl;
        }
        // tail = head;
        tail = head;
        tail->next = NULL;

        head = previous;
        cout << "head: " << head->next << ", " << head->data << endl;
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
    list.addLast(2);
    list.addLast(4);
    list.addLast(6);
    list.addLast(8);
    list.addLast(10);
    list.addLast(12);
    list.printNode();

    list.deleteLast();
    list.deleteFirst();

    list.printNode();

    cout << "Index: " << list.indexOf(10) << endl;
    cout << "List Size: " << list.size() << endl;
    cout << "Contains 10: " << list.contains(10) << endl;

    list.reverse();
    list.printNode();
    int *val = list.toArray();

    for (int i = 0; i < list.size(); i++)
    {
        cout << val[i] << endl;
    }
    return 0;
}