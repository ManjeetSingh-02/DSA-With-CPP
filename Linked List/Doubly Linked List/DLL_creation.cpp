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