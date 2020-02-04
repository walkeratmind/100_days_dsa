#include <iostream>

#define MAX 10

using namespace std;

struct StackOverflow : public exception
{
    const char *what() const throw()
    {
        return "Stack Overflow";
    }
};

struct StackUnderflow : public exception
{
    const char *what() const throw()
    {
        return "Stack Underflow";
    }
};

class Stack
{
private:
    int items[MAX];
    int count;
    int size;

public:
    Stack(int size)
    {
        count = 0;
        this->size = size;
        items[size];
    };

    void push(int item)
    {
        if (count == size)
        {
            throw StackOverflow();
        }
        else
        {

            items[count++] = item;
        }
    }
    int pop()
    {
        if (count == 0)
        {
            throw StackUnderflow();
        }
        return items[--count];
    }

    int peek()
    {
        if (count == 0)
        {
            throw StackUnderflow();
        }
        return items[count - 1];
    }

    int min()
    {
        if (count == 0)
        {
            throw StackUnderflow();
        }
        int min = items[0];
        for (int i = 1; i < count; i++)
        {

            min = min < items[i] ? min : items[i];
        }
        return min;
    }

    int *toArray()
    {
        int arr[MAX];

        for (int i = 0; i < count; i++)
        {
            arr[i] = items[count];
        }

        return arr;
    }

    bool isEmpty()
    {
        return count == 0;
    }

    bool isFull()
    {
        return count == size;
    }

    void printStack()
    {
        for (int i = count - 1; i >= 0; i--)
        {
            cout << "Count: " << i << " Item: " << items[i] << endl;
        }
    }
};

int main()
{
    Stack stack = Stack(5);

    cout << "isEmpty: " << stack.isEmpty() << endl;

    // stack.pop();
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.push(10);

    stack.push(12);

    stack.printStack();

    cout << "isFull: " << stack.isFull() << endl;
    stack.pop();
    cout << "After pop Operation:" << endl;
    stack.printStack();

    cout << "isFull: " << stack.isFull() << endl;
    cout << "Peek: " << stack.peek() << endl;
    stack.push(1);
    cout << "Min Value: " << stack.min() << endl;
    return 0;
}
