#include <iostream>
using namespace std;

void max_heapify(int a[], int);
void display();

int a[100], max_elements = -1;

int main()
{
    int n;
    cout << "Enter size of array (Less than 100): ";
    cin >> n;
    if (n > 100)
    {
        cout << "Elements must be less than 100" << endl;
        exit(0);
    }
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        max_elements++;
        cin >> a[max_elements];
    }

    for (int i = (max_elements / 2); i >= 0; i--)
        max_heapify(a, i);

    display();
    return 0;
}

void max_heapify(int a[], int i)
{
    int par = i, lc = (2 * i) + 1, rc = (2 * i) + 2, i_large;

    if (a[lc] > a[par] && lc <= max_elements)
        i_large = lc;
    else
        i_large = par;

    if (a[i_large] < a[rc] && rc <= max_elements)
        i_large = rc;

    if (i_large != i)
    {
        int t = a[i_large];
        a[i_large] = a[i];
        a[i] = t;
        max_heapify(a, i_large);
    }
}

void display()
{
    cout << "After Sorting :" << endl;
    for (int i = 0; i <= max_elements; i++)
        cout << "Parent - " << a[i] << " || LeftChild - " << a[(2 * i) + 1] << " || RightChild - " << a[(2 * i) + 2] << endl;
}