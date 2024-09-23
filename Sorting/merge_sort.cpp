#include <iostream>
using namespace std;

void merge(int a[], int, int, int);
void dnc(int arr[], int, int);

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int a[n];
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    dnc(a, 0, n - 1);

    cout << "After Sorting :" << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << endl;
    return 0;
}

void dnc(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = lb + (ub - lb) / 2;
        dnc(arr, lb, mid);
        dnc(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
    }
}

void merge(int a[], int l, int m, int u)
{
    int n1 = m - l + 1, n2 = u - m, i, j, k;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (i = 0; i < n2; i++)
        R[i] = a[m + 1 + i];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] < R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}