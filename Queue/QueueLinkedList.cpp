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

class queue_LL
{

    node *head;
    int count;

public:
    queue_LL()
    {
        head = nullptr;
        count = 0;
    }

    bool is_empty()
    {
        return head == nullptr;
    }

    void enqueue(int val)
    { // enqueue would be the same as add from tail
        node *newnode = new node();
        node *temp = head; // to reach the tail
        newnode->data = val;

        if (is_empty())
        { // case 1 : adding the first ever node
            newnode->next = nullptr;
            head = newnode;
        }
        else
        {
            while (temp->next != nullptr)
            { // so we stop at the last node
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = nullptr;
        }
        count++;
    }

    void dequeue()
    { // dequeue would be the same as delete from head
        if (is_empty())
        {
            return void(cout << "the list is empty\n");
        }
        else
        {

            node *delptr = head;
            head = head->next;
            delete delptr;
        }
        count--;
    }

    int peek()
    {
        if (is_empty())
        {
            cout << "the queue is empty\n";
            return -1;
        }

        return head->data;
    }

    int search(int target)
    { // returns the index of the target and if not found returns -1
        if (is_empty())
        {
            cout << "the queue is empty\n";
            return -1;
        }

        int pos = 0;
        node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == target)
                return pos;

            temp = temp->next;
            pos++;
        }

        return -1;
    }

    int size()
    {
        return count;
    }

    void print()
    {
        if (is_empty())
            return void(cout << "the queue is empty\n");

        node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main()
{
    queue_LL q;
}