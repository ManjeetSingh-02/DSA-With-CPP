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
void insertatsp(int, int, int);
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

    cout << "Enter Element You Want To Insert: ";
    cin >> x;
    cout << "Enter position of the element you want to insert: ";
    cin >> y;

    if (y == 0)
    {
        cout << "Position Must Be More Than 0" << endl;
        exit(0);
    }
    else if (y > (n + 1))
    {
        cout << "Position Must Be Less Or Equal To " << n + 1 << endl;
        exit(0);
    }
    else
        insertatsp(x, y, n);

    cout << "After Insertion , List Is :" << endl;
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

void insertatsp(int x, int y, int max)
{
    ListNode *temp = new ListNode(x);
    int i = 1;

    if (y == 1)
    {
        temp->right = head;
        head->left = temp;
        head = temp;
    }
    else
    {
        ListNode *p = head;
        while (i < (y - 1))
        {
            p = p->right;
            i++;
        }
        temp->right = p->right;
        temp->left = p;
        p->right = temp;
        p = temp->right;
        if (y != (max + 1))
            p->left = temp;
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