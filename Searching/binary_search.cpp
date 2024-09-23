#include <iostream>
using namespace std;

int main()
{
    int n, x, high, low, mid;

    cout << "Enter size of array: ";
    cin >> n;
    int a[n];
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter the element you want to search: ";
    cin >> x;
    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low <= high)
    {
        if (a[mid] == x)
        {
            cout << "Element Found At " << mid + 1 << " Position" << endl;
            break;
        }
        else if (a[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
        mid = (low + high) / 2;
    }

    if (low > high)
        cout << "Element Is Not In The List" << endl;
    return 0;
}