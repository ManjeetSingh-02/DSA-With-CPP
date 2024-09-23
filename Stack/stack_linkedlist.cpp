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
int top = 0, max_elements;

void push(int x);
void pop();
void display();

int main()
{
	int x;

	cout << "Enter How Many Elements You Want To Push In Stack: ";
	cin >> max_elements;
	cout << "Enter " << max_elements << " elements:" << endl;
	for (int i = 0; i < max_elements; i++)
	{
		cin >> x;
		push(x);
	}
	cout << "Stack Created, Elements are:" << endl;
	display();
	cout << "Enter How Many Elements you want to pop: ";
	cin >> x;
	if (x > max_elements)
	{
		cout << "Number of elements that can be pop must be less than or equal to " << max_elements << endl;
		exit(0);
	}
	for (int i = 0; i < x; i++)
		pop();
	cout << "After Pop operations, Elements are:" << endl;
	display();
	return 0;
}

void push(int x)
{
	if (top > max_elements)
		cout << "Stack is overflowing" << endl;
	else
	{
		ListNode *temp = new ListNode(x);
		if (head == nullptr)
		{
			top++;
			head = temp;
		}
		else
		{
			top++;
			temp->next = head;
			head = temp;
		}
	}
}

void pop()
{

	if (top == -1)
		cout << "Stack is underflowing" << endl;
	else
	{
		ListNode *p = head;
		top--;
		head = head->next;
		p->next = nullptr;
	}
}

void display()
{
	ListNode *p = head;
	while (p != nullptr)
	{
		cout << p->data << endl;
		p = p->next;
	}
}