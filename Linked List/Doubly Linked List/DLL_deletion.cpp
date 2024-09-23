#include <iostream>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *left;
    ListNode *right;
    ListNode(int d)
    {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

ListNode *head = nullptr;

void create(int);
void deleteatsp(int, int);
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
        deleteatsp(x, n);

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
        while (p->right != nullptr)
            p = p->right;
        temp->left = p;
        p->right = temp;
    }
}

void deleteatsp(int x, int max)
{
    int i = 1;
    if (x == 1)
    {
        ListNode *p = head;
        head = head->right;
        p->right = nullptr;
    }
    else
    {
        ListNode *p = head, *q;
        while (i < x)
        {
            q = p;
            p = p->right;
            i++;
        }
        q->right = p->right;
        if (x != max)
        {
            q = q->right;
            q->left = p->left;
        }
        p->left = nullptr;
        p->right = nullptr;
    }
}

void display()
{
    ListNode *p = head;
    while (p->right != nullptr)
    {
        cout << p->data << endl;
        p = p->right;
    }
    cout << p->data << endl;
}