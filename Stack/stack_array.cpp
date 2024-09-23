#include <iostream>
using namespace std;

int top = -1, max_elements, a[100];

void push(int x);
void pop();
void display();

int main()
{
	int x;

	cout << "Enter How Many Elements You Want To Push In Stack (Less than 100): ";
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
	if (top >= max_elements - 1)
		cout << "Stack is overflowing" << endl;
	else
	{
		top++;
		a[top] = x;
	}
}

void pop()
{
	if (top == -1)
		cout << "Stack is underflowing" << endl;
	else
		top--;
}

void display()
{
	for (int i = top; i >= 0; i--)
		cout << a[i] << endl;
}