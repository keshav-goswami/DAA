// II. Given an unsorted array of integers, design an algorithm and implement it using a program to find whether two elements exist such that their sum is equal to the given key element. (Time Complexity = O(n log n).

#include <iostream>
#include <algorithm>
using namespace std;
int Binary_search(int arr[], int l, int r, int key)
{
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            l = mid + 1;
        }
        else if (arr[mid] > key)
        {
            r = mid;
        }
    }
    return -1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, target;
        bool flag = false;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        sort(arr,arr+n); 
        cin >> target;
        for (int i = 0; i < n; i++)
        {
            if ((target - arr[i]) > 0)
            {
                if (Binary_search(arr,i,n-1,target - arr[i]) != -1)
                {
                    flag = true;
                    cout << arr[i] << " " << target - arr[i] << endl;
                }
            }
        }
        if (!flag)
            cout << "No Such Pair Exists" << endl;
    }
    return 0;
}