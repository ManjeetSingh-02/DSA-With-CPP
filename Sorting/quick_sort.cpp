#include <iostream>
using namespace std;

void quicksort(int a[], int, int);

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int a[n];
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    quicksort(a, 0, n - 1);

    cout << "After Sorting :" << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << endl;
    return 0;
}

void quicksort(int a[], int first, int last)
{
    if (first < last)
    {
        int pivot = first;
        int i = first;
        int j = last;

        while (i < j)
        {
            while (a[i] <= a[pivot] && i < last)
                i++;
            while (a[j] > a[pivot])
                j--;
            if (i < j)
            {
                int k = a[i];
                a[i] = a[j];
                a[j] = k;
            }
        }
        int k = a[pivot];
        a[pivot] = a[j];
        a[j] = k;

        quicksort(a, first, j - 1);
        quicksort(a, j + 1, last);
    }
}