#include <bits/stdc++.h>
#include "StackUsingLinkedList.cpp"
using namespace std;

string reverse_string(string s)
{
    Stack_LL<char> st;
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
    Stack_LL<char> st;
    st.push(s[0]); // to push the first "(" or "{" or "["
    for (int i = 1; i < s.size(); i++)
    {
        /*
            We have two cases while pushing: either the stack is empty,
            which means we have matched all previous brackets so we push
            the current bracket, or the stack still has open brackets
            so we check if the current one matches the top element.
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

int priority(char op)
{ // priority for the operator in the infix
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

string infix_to_postfix(string infix) // 1+(2*3)+4 => 123*+4+
{

    /*
        Logic for Infix to Postfix Conversion :
        1. Operands (Numbers): Add directly to the postfix string.
        2. Left Parenthesis '(': Push onto the stack to start a new priority scope.
        3. Right Parenthesis ')': Pop and append to postfix until '(' is encountered.
        4. Operators (+, -, *, /):
            - Pop and append operators from the stack as long as they have
                HIGHER or EQUAL priority than the current operator.
            - Push the current operator onto the stack.
        5. Cleanup: After the loop, pop all remaining operators from the stack.
    */
    Stack_LL<char> st;
    string postfix = "";

    for (char &c : infix)
    {

        if (isdigit(c))
        {
            postfix += c;
        }

        else if (c == '(')
        {
            st.push(c);
        }

        else if (c == ')')
        {

            while (!st.is_empty() && st.peek() != '(')
            {
                postfix += st.peek();
                st.pop();
            }

            if (!st.is_empty())
                st.pop();
        }

        else
        {

            while (!st.is_empty() && st.peek() != '(' && priority(st.peek()) >= priority(c))
            {
                postfix += st.peek();
                st.pop();
            }

            st.push(c);
        }
    }

    while (!st.is_empty())
    {
        postfix += st.peek();
        st.pop();
    }

    return postfix;
}

int postfix_eval(string postfix)
{
    Stack_LL<int> st;

    for (int i = 0; i < postfix.size(); i++)
    {
        if (postfix[i] == ' ')
            continue;

        if (isdigit(postfix[i]))
        {
            int num = 0;
            while (i < postfix.size() && isdigit(postfix[i]))
            {
                num = num * 10 + (postfix[i] - '0'), i++;
            }

            st.push(num);
            i--;
        }
        else
        {
            int second = st.peek();
            st.pop();
            int first = st.peek();
            st.pop();

            if (postfix[i] == '+')
                st.push(first + second);
            else if (postfix[i] == '-')
                st.push(first - second);
            else if (postfix[i] == '*')
                st.push(first * second);
            else if (postfix[i] == '/')
                st.push(first / second);
            else
                st.push(pow(first, second));
        }
    }
    return st.peek();
}

int main()
{
    Stack_LL<char> stack;
}