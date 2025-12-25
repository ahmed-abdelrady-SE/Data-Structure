#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 100; // a global variable that cannot be changed to refer to the max size

class Stack_array
{
public:
    int top;
    int stack[100];

    Stack_array()
    {
        top = -1;
    }

    bool is_empty()
    {
        return top == -1;
    }

    bool is_full()
    {
        return top == MAX_SIZE - 1;
    }

    void push(int data)
    {
        if (is_full())
        {
            cout << "the stack is full\n";
            return;
        }
        stack[++top] = data;
    }

    void pop()
    {
        if (is_empty())
        {
            cout << "the stack is empty there is nothing to pop\n";
            return;
        }
        top--;
    }

    int peek()
    {
        if (is_empty())
        {
            cout << "the stack is empty\n";
            return -1;
        }

        return stack[top];
    }

    int size()
    {
        return top + 1;
    }

    void print()
    {
        for (int i = top; i >= 0; i--)
        { // we have to traverse backward because the stack follows the LIFO principles
            cout << stack[i] << " ";
        }
        cout << "\n";
    }
};

int main()
{
    Stack_array stack;
}