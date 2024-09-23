#include <iostream>
using namespace std;

int main()
{
    int n, x, flag = 0;
    cout << "Enter size of array: ";
    cin >> n;
    int a[n];
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter the element you want to search: ";
    cin >> x;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            cout << "Element Found At " << i + 1 << " Position" << endl;
            flag = 1;
            break;
        }
    }

    if (flag == 0)
        cout << "Element Is Not In The List" << endl;
    return 0;
}