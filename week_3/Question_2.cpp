// II. Given an unsorted array of integers, design an algorithm and implement a program to sort this array using selection sort. Your program should also find number of comparisons and number of swaps required.

#include <iostream>
using namespace std;
void Selection_sort(int a[], int size)
{
    int c = 0, s = 0;
    for (int i = 0; i < size-1; i++)
    {
        int temp = i;
        for(int j=i+1;j<size;j++)
        {
            if(a[temp]>a[j]) temp = j; 
            c++;
        }
        if(temp!=i){
            cout<<a[temp];
            int sw = a[i];
            a[i] = a[temp];
            a[temp] = sw;
            s++;
        }
    }

    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
    cout << "Comparisons: " << c << endl;
    cout << "Swaps: " << s << endl;
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
        Selection_sort(a, n);
        cout << endl;
    }
    return 0;
}