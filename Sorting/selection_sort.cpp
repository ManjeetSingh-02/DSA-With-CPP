#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int a[n];
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    cout << "After Sorting :" << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << endl;
    return 0;
}