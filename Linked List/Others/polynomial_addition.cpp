#include <iostream>
using namespace std;

class ListNode
{
public:
	int coeff;
	int pow;
	ListNode *next;
	ListNode(int a, int b)
	{
		coeff = a;
		pow = b;
		next = nullptr;
	}
};

ListNode *polym = nullptr;
ListNode *poly1 = nullptr;
ListNode *poly2 = nullptr;

void enterpoly(int, int, int);
void addtwopoly();
void result(int, int);
void display();

int main()
{
	int a, b, tp1, tp2;

	cout << "Enter The No Of Terms In Polynomial-1 : ";
	cin >> tp1;
	if (tp1 == 0)
	{
		cout << "Terms Should Be More Than 0" << endl;
		exit(0);
	}
	else
	{
		for (int i = 0; i < tp1; i++)
		{
			cout << "Enter Polynomial-1 -> Term - " << i + 1 << " -> Coefficient : ";
			cin >> a;
			cout << "Enter Polynomial-1 -> Term - " << i + 1 << " -> Power : ";
			cin >> b;
			enterpoly(a, b, 1);
		}
	}

	cout << "Enter The No Of Terms In Polynomial-2 : ";
	cin >> tp2;
	if (tp2 == 0)
	{
		cout << "Terms Should Be More Than 0" << endl;
		exit(0);
	}
	else
	{
		for (int i = 0; i < tp2; i++)
		{
			cout << "Enter Polynomial-2 -> Term - " << i + 1 << " -> Coefficient : ";
			cin >> a;
			cout << "Enter Polynomial-2 -> Term - " << i + 1 << " -> Power : ";
			cin >> b;
			enterpoly(a, b, 2);
		}
	}

	addtwopoly();
	display();
	return 0;
}

void enterpoly(int x, int y, int z)
{
	ListNode *temp = new ListNode(x, y);
	if (z == 1)
	{
		if (poly1 == nullptr)
			poly1 = temp;
		else
		{
			ListNode *p = poly1;
			while (p->next != nullptr)
				p = p->next;
			p->next = temp;
		}
	}
	else
	{
		if (poly2 == nullptr)
			poly2 = temp;
		else
		{
			ListNode *p = poly2;
			while (p->next != nullptr)
				p = p->next;
			p->next = temp;
		}
	}
}

void addtwopoly()
{
	ListNode *temp = new ListNode(0, 0), *p = poly1, *q = poly2;
	while (p != nullptr && q != nullptr)
	{
		if (p->pow == q->pow)
		{
			temp->coeff = p->coeff + q->coeff;
			temp->pow = p->pow;
			p = p->next;
			q = q->next;
		}
		else if (p->pow >= q->pow)
		{
			temp->coeff = p->coeff;
			temp->pow = p->pow;
			p = p->next;
		}
		else
		{
			temp->coeff = q->coeff;
			temp->pow = q->pow;
			q = q->next;
		}
		result(temp->coeff, temp->pow);
	}

	if (p == nullptr)
	{
		while (q != nullptr)
		{
			result(q->coeff, q->pow);
			q = q->next;
		}
	}
	else
	{
		while (p != nullptr)
		{
			result(p->coeff, p->pow);
			p = p->next;
		}
	}
}

void result(int x, int y)
{
	ListNode *temp = new ListNode(x, y);

	if (polym == nullptr)
		polym = temp;
	else
	{
		ListNode *z = polym;
		while (z->next != nullptr)
			z = z->next;
		z->next = temp;
	}
}

void display()
{
	ListNode *p = polym;
	while (p != nullptr)
	{
		if (p->pow == 0)
			cout << "+(" << p->coeff << ")";
		else if (p->pow == 1)
			cout << "+(" << p->coeff << "x)";
		else
			cout << "+(" << p->coeff << "x^" << p->pow << ")";
		p = p->next;
	}
}