#include <iostream>
using namespace std;

int main()
{
    int n, y, x;
    cout << "Enter size of array: ";
    cin >> n;
    int a[n];
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter New Element You Want To Be Insert : ";
    cin >> x;
    cout << "Enter The Position Where You Want To Insert New Element : ";
    cin >> y;

    if (y > 10)
        cout << "Position Cannot Be More Than " << n << endl;
    else
    {
        y--;
        for (int i = 10; i >= y; i--)
            a[i + 1] = a[i];
        a[y] = x;
        cout << "After Insertion :" << endl;
        for (int i = 0; i < 10; i++)
            cout << a[i] << endl;
    }
    return 0;
}