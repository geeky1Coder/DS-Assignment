#define MAX_SIZE 5
#include <bits/stdc++.h>
using namespace std;
class My_queue
{
    int front;
    int rear;
    int size;
    int *queue_arr;

public:
    My_queue() : front{-1}, rear{-1}, size{0}
    {
        queue_arr = new int[MAX_SIZE];
    }
    ~My_queue()
    {
        delete[] queue_arr;
    }
    void enque(int element)
    {
        if ((front == 0 && rear == MAX_SIZE - 1) || (rear == front - 1 % (MAX_SIZE - 1)))
        {
            cout << "Queue is full";
            return;
        }
        else if (front == -1)
        {
            front = rear = 0;
            queue_arr[rear] = element;
            ++size;
        }
        else if (rear == MAX_SIZE - 1 && front != 0)
        {
            rear = 0;
            queue_arr[rear] = element;
            ++size;
        }
        else
        {
            rear++;
            queue_arr[rear] = element;
            size++;
        }
    }
    int deque()
    {
        if (front == -1)
        {
            cout << "queue is empty" << endl;
            return INT_MIN;
        }
        int data = queue_arr[front];
        queue_arr[front] = -1;
        if (front == rear)
        {
            front = -1;
            rear = -1;
            size--;
        }
        else if (front == MAX_SIZE - 1)
        {
            front = 0;
            size--;
        }
        else
        {
            front++;
            size--;
        }
        return data;
    }
    void display()
    {
        if (front == -1)
        {
            cout << "Queue is empty";
        }
        else if (front <= rear)
        {
            for (int i = front; i <= rear; ++i)
            {
                cout << queue_arr[i] << " ";
            }
        }
        else
        {
            for (int i = front; i != MAX_SIZE; ++i)
            {
                cout << queue_arr[i] << " ";
            }
            for (int i = 0; i <= rear; ++i)
            {
                cout << queue_arr[i] << " ";
            }
        }
        cout << endl;
    }
};

int main()
{
    My_queue q{};
    q.enque(50);
    q.enque(70);
    q.enque(80);
    q.enque(40);
    q.enque(70);
    q.deque();
    q.deque();
    q.deque();
    q.enque(10);
    q.display();
    return 0;
}