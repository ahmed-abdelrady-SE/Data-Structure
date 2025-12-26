#include <bits/stdc++.h>
using namespace std;

class node
{

public:
    char data;
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

    char peek()
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

string reverse_string(string s)
{
    Stack_LL st;
    for (char &c : s)
        st.push(c);
    string reversed = "";
    while (!st.is_empty())
    {
        reversed += st.peek();
        st.pop();
    }
    return reversed;
}

bool check_balance(string s)
{
    Stack_LL st;
    st.push(s[0]); // to push the first "("
    for (int i = 1; i < s.size(); i++)
    {
        /*
            we had two cases while pushing eathir the stack is empty which mean we deleted all duplicates so we gonna push again with no worries
            or there is still duplicates so we had to check for the top element
        */

        if (st.is_empty())
        {
            st.push(s[i]);
        }
        else
        {
            if ((st.peek() == '(' && s[i] == ')') || (st.peek() == '{' && s[i] == '}') || (st.peek() == '[' && s[i] == ']'))
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
    }

    if (st.is_empty())
        return true;
    else
        return false;
}

string infix_to_postfix(string infix)
{
    
}

int postfix_eval(string postfix)
{
}

int main()
{
    Stack_LL stack;
}