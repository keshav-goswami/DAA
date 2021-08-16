// II. Given a sorted array of positive integers, design an algorithm and implement it using a program
// to find three indices i, j, k such that arr[i] + arr[j] = arr[k].

#include <iostream>
using namespace std;
int Binary_Search(int arr[], int start, int end, int key)
{
    if (end >= start)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
            return mid;
        else if (key > arr[mid])
            return Binary_Search(arr, (mid + 1), end, key);
        else
            return Binary_Search(arr, start, (mid - 1), key);
    }
    return -1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        bool flag = false;
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int key = a[i] + a[j];
                int k = Binary_Search(a, 0, n - 1, key);
                if (k != -1)
                {
                    cout << i+1 << " " << j+1 << " " << k+1 << endl;
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        if(!flag) cout<<"No Sequence Found"<<endl;
    }
    return 0;
}