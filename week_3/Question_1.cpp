// I. Given an unsorted array of integers, design an algorithm and a program to sort the array using insertion sort. Your program should be able to find number of comparisons and shifts (shifts total number of times the array elements are shifted from their place) required for sorting the array.

#include <iostream>
using namespace std;
void Insertion_sort(int a[], int size)
{
    int c = 0, s = 0;
    for (int i = 1; i < size; i++)
    {
        int temp = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            s++;
            c++;
            j--;
        }
        c++;
        a[j + 1] = temp;
    }

    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
    cout << "Comparisons: " << c << endl;
    cout << "Shifts: " << s << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Insertion_sort(a, n);
        cout << endl;
    }
    return 0;
}