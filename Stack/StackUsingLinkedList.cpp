#include <bits/stdc++.h>
using namespace std;

class node
{

public:
    int data;
    node *next;

    node()
    {
        data = 0;
        next = nullptr;
    }
};

class Stack_LL
{
public:
    node *top;
    Stack_LL()
    {
        top = nullptr;
    }

    bool is_empty()
    {
        return !top;
    }

    void push(int data)
    {
        node *newnode = new node();
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
            node *delptr = top;
            top = top->next;
            delete delptr;
        }
    }

    int peek()
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
            node *temp = top;
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
        node *temp = top;
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

int main()
{
    Stack_LL stack;
}