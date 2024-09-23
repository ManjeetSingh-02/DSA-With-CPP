#include <iostream>
using namespace std;

int main()
{
    int n, x;
    cout << "Enter size of array: ";
    cin >> n;
    int a[n];
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Enter The Position Where You Want To Delete Element : ";
    cin >> x;

    if (x > 10)
        cout << "Position Cannot Be More Than " << n << endl;
    else
    {
        x-- ;
        for(int i = x ; i < 10 ; i++)
            a[i] = a[i+1] ;
        cout << "After Deletion :" << endl ;
        for(int i = 0 ; i < 10 ; i++)
            cout << a[i] << endl;
    }
    return 0;
}