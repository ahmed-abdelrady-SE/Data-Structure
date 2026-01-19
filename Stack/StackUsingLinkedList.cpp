#include <bits/stdc++.h>
using namespace std;

template <typename T>
class node
{

public:
    T data;
    node<T> *next;

    node()
    {
        data = 0;
        next = nullptr;
    }
};
template <typename T>
class Stack_LL
{
public:
    node<T> *top;
    Stack_LL()
    {
        top = nullptr;
    }

    bool is_empty()
    {
        return !top;
    }

    void push(T data)
    {
        node<T> *newnode = new node<T>();
        newnode->data = data;
        newnode->next = top;
        top = newnode;
    }

    void pop()
    {
        if (is_empty())
        {
            return void(cout << "the stack is empty\n");
        }
        else
        {
            node<T> *delptr = top;
            top = top->next;
            delete delptr;
        }
    }

    T peek()
    {
        if (is_empty())
        {
            cout << "The stack is empty\n";
            return -1;
        }
        return top->data;
    }

    int size()
    {
        if (is_empty())
        {
            cout << "the stack is empty\n";
            return 0;
        }
        else
        {
            node<T> *temp = top;
            int cnt = 0;
            while (temp != nullptr)
            {
                cnt++;
                temp = temp->next;
            }
            return cnt;
        }
    }

    void print()
    {
        node<T> *temp = top;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

    ~Stack_LL()
    {
        while (!is_empty())
        {
            pop();
        }
    }
};