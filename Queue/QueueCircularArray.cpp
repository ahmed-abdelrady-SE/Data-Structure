#include <bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 100; // a global variable that cannot be changed to refer to the max size

class circularqueue
{

    int front, rear, count;
    int arr[MAX_SIZE];

public:
    circularqueue()
    {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool is_empty()
    {
        return count == 0;
    }

    bool is_full()
    {
        return count == MAX_SIZE;
    }

    void enqueue(int data)
    {
        if (is_full())
        {
            return void(cout << "the queue is full");
        }

        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = data;

        count++;
    }

    void dequeue()
    {
        if (is_empty())
        {
            return void(cout << "the queue is empty");
        }

        front = (front + 1) % MAX_SIZE;
        count--;
    }

    int peek()
    {
        if (is_empty())
        {
            cout << "the queue is empty";
            return -1;
        }

        return arr[front];
    }

    int search(int target)
    {
        int pos = -1;
        if (is_empty())
        {
            cout << "the queue is empty\n";
        }
        else if (target == arr[rear])
            return rear;

        else
        {
            for (int i = front; i != rear; i = (i + 1) % MAX_SIZE)
            {
                if (arr[i] == target)
                {
                    pos = i;
                    break;
                }
            }
        }

        if (pos == -1)
        {
            cout << "the item is not found in the queue\n";
        }

        return pos;
    }

    int size()
    {
        return count;
    }

    void print()
    {
        if (is_empty())
        {
            return void(cout << "the queue is empty");
        }

        for (int i = front; i != rear; i = (i + 1) % MAX_SIZE)
        {
            cout << arr[i] << " ";
        }
        cout << arr[rear] << "\n";
    }
};

int main()
{
    circularqueue q;
}