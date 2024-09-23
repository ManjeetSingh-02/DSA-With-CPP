#include <iostream>
using namespace std;

int front = -1, rear = -1, max_elements, a[100];

void enque(int);
void deque();
void display();

int main()
{
    int x;

    cout << "Enter How Many Elements You Want To Add In Queue (Less than 100): ";
    cin >> max_elements;
    if (max_elements > 100)
    {
        cout << "Elements must be less than 100" << endl;
        exit(0);
    }
    cout << "Enter " << max_elements << " elements:" << endl;
    for (int i = 0; i < max_elements; i++)
    {
        cin >> x;
        enque(x);
    }
    cout << "Queue Created, Elements are:" << endl;
    display();
    cout << "Enter How Many Elements you want to delete: ";
    cin >> x;
    if (x > max_elements)
    {
        cout << "Number of elements that can be pop must be less than or equal to " << max_elements << endl;
        exit(0);
    }
    for (int i = 0; i < x; i++)
        deque();
    cout << "After delete operations, Elements are:" << endl;
    display();
    return 0;
}

void enque(int x)
{
    if (rear >= max_elements - 1)
        cout << "Queue is overflowing" << endl;
    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        a[rear] = x;
    }
    else
    {
        rear++;
        a[rear] = x;
    }
}

void deque()
{
    if (front == -1)
        cout << "Queue is empty" << endl;
    else if (front > rear)
        cout << "Queue is underflowing" << endl;
    else
        front++;
}

void display()
{
    for (int i = front; i <= rear; i++)
        cout << a[i] << endl;
}