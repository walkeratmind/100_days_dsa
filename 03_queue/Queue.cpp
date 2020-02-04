#include <iostream>
#include <stdexcept>

#define MAX 10

using namespace std;

class Queue
{
private:
    int items[MAX];
    int front;
    int rear;
    int size;

public:
    Queue(int size) : front(0), rear(0), size(size) { items[size]; };

    void enque(int item)
    {
        if (rear == size)
        {
            throw overflow_error("Queue Overflow");
        }
        items[rear++] = item;
    }

    int dequue()
    {
        if (rear == 0)
        {
            throw underflow_error("Queue Underflow");
        }
        int item = items[0];
        items[front++] = 0;
        return item;
    }

    int peek()
    {
        if (rear == 0)
        {
            throw underflow_error("Queue Underflow");
        }
        return items[front];
    }

    int totalItems()
    {
        return rear - front;
    }

    bool isEmpty()
    {
        return front == rear;
    }

    void printQueue()
    {
        for (int i = 0; i < rear; i++)
        {
            cout << "Count: " << i << " Item: " << items[i] << endl;
        }
    }
};

int main()
{
    Queue queue = Queue(5);
    queue.enque(9);
    queue.enque(8);
    queue.enque(7);
    queue.enque(6);
    queue.enque(5);

    queue.printQueue();
    queue.dequue();
    queue.dequue();
    cout << "After deque: " << endl;
    queue.printQueue();
    cout << "Peek: " << queue.peek() << endl;
    cout << "Total Items: " << queue.totalItems() << endl;
    // queue.enque(4);
}