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
int front = 0, rear = 0, max_elements;

void enque(int x);
void deque();
void display();

int main()
{
	int x;

	cout << "Enter How Many Elements You Want To Add In Queue: ";
	cin >> max_elements;
	cout << "Enter " << max_elements << " elements:" << endl;
	for (int i = 0; i < max_elements; i++)
	{
		cin >> x;
		enque(x);
	}
	cout << "Queue Created, Elements are:" << endl;
	display();
	cout << "Enter How Many Elements you want to pop: ";
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
	if (rear > max_elements - 1)
		cout << "Queue is overflowing" << endl;
	else
	{
		ListNode *temp = new ListNode(x);
		if (head == nullptr)
		{
			front = 1;
			rear = 1;
			head = temp;
		}
		else
		{
			ListNode *p = head;
			rear++;
			while (p->next != nullptr)
				p = p->next;
			p->next = temp;
		}
	}
}

void deque()
{
	if (front == 0)
		cout << "Queue is empty" << endl;
	else if (front > rear)
		cout << "Queue is underflowing" << endl;
	else
	{
		ListNode *p = head;
		front++;
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