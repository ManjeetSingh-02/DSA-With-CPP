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
void deleteatsp(int);
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

    cout << "Enter position of the element you want to delete: ";
    cin >> x;

    if (x == 0)
    {
        cout << "Position Must Be More Than 0" << endl;
        exit(0);
    }
    else if (x > n)
    {
        cout << "Position Must Be Less Or Equal To " << n << endl;
        exit(0);
    }
    else
        deleteatsp(x);

    cout << "After Deletion , List Is :" << endl;
    display();
    return 0;
}

void create(int x)
{
    ListNode *temp = new ListNode(x);

    if (head == nullptr)
        head = temp;
    else
    {
        ListNode *p = head;
        while (p->next != nullptr)
            p = p->next;
        p->next = temp;
    }
}

void deleteatsp(int x)
{
    int i = 1;
    if (x == 1)
    {
        ListNode *p = head;
        head = head->next;
        p->next = nullptr;
    }
    else
    {
        ListNode *p = head, *q;
        while (i < x)
        {
            q = p;
            p = p->next;
            i++;
        }
        q->next = p->next;
        p->next = nullptr;
    }
}

void display()
{
    ListNode *p = head;
    cout << "HEAD --> ";
    while (p != nullptr)
    {
        cout << p->data << " -- > ";
        p = p->next;
    }
    cout << "END" << endl;
}