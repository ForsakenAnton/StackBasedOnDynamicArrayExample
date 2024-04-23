#include <iostream>
using namespace std;

template <typename T>
class Stack 
{
private:
    T* arr; // Динамічний масив для зберігання даних
    int capacity; // Розмір масиву
    int topIndex; // Індекс вершини стеку

public:
    Stack(int size = 10) : capacity(size), topIndex(-1)
    {
        arr = new T[capacity];
    }

    ~Stack()
    {
        delete[] arr;
    }

    bool isEmpty() const
    {
        return topIndex == -1;
    }

    bool isFull() const
    {
        return topIndex == capacity - 1;
    }

    void push(const T& value)
    {
        if (isFull())
        {
            cerr << "Stack is full. Cannot push." << endl;
            return;
        }

        arr[++topIndex] = value;
    }

    void pop()
    {
        if (isEmpty())
        {
            cerr << "Stack is empty. Cannot pop." << endl;
            return;
        }

        topIndex--;
    }

    const T& peek() const
    {
        if (isEmpty())
        {
            cerr << "Stack is empty." << endl;

            static T dummy;
            return dummy;
        }

        return arr[topIndex];
    }
};

int main()
{
    Stack<int> myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);

    cout << "Top of the stack: " << myStack.peek() << endl;

    myStack.pop();
    cout << "After pop:" << endl;
    cout << "Top of the stack: " << myStack.peek() << endl;

    return 0;
}
