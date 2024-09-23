#include <iostream>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode(int d)
    {
        data = d;
        next = nullptr;
    }
};

ListNode *head = nullptr;

void create(int);
void display();

int main()
{
    int x, n;

    cout << "Enter Total No OF Elements : ";
    cin >> n;
    cout << "Enter " << n << " Elements :" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        create(x);
    }

    cout << "Linked List Created :" << endl;
    display();
    return 0;
}

void create(int x)
{
    ListNode *temp = new ListNode(x);
    if (head == nullptr)
    {
        temp->next = temp;
        head = temp;
    }
    else
    {
        ListNode *p = head;
        while (p->next != head)
            p = p->next;
        temp->next = head;
        p->next = temp;
    }
}

void display()
{
    ListNode *p = head;
    cout << "HEAD --> ";
    while (p->next != head)
    {
        cout << p->data << " -- > ";
        p = p->next;
    }
    cout << p->data << " -- > ";
    cout << p->next->data << "(HEAD)" << endl;
}