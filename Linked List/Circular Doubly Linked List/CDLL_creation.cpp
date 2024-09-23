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
void display();

int main()
{
    int x, y, n;

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
        temp->left = temp;
        temp->right = temp;
        head = temp;
    }
    else
    {
        ListNode *p = head;
        while (p->right != head)
            p = p->right;
        temp->left = p;
        p->right = temp;
        temp->right = head;
        head->left = temp;
    }
}

void display()
{
    ListNode *p = head;
    while (p->right != head)
    {
        cout << p->data << endl;
        p = p->right;
    }
    cout << p->data << endl;
}