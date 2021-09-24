// You have been given two sorted integer arrays of size m and n. Design an algorithm and implement it using a program to find list of elements which are common to both. (Time complexity=O(m+n)) .

#include <iostream>
using namespace std;

void SameElements(int arr1[], int arr2[], int m, int n)
{
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (arr1[i] < arr2[j])
            i++;
        else if (arr2[j] < arr1[i])
            j++;
        else if(arr1[i] == arr2[j])
        {
            cout << arr2[j] << " ";
            i++;
            j++;
        }
    }
}

int main()
{
int t;
    cin >> t;
    while (t--)
    {
        int m,n,target;
        bool flag = false;
        cin >> m;
        int arr1[m];
        for (int i = 0; i < m; i++) cin >> arr1[i];
        cin >> n;
        int arr2[n];
        for (int i = 0; i < n; i++) cin >> arr2[i]; 
        SameElements(arr1,arr2,m,n);
    }
    return 0;
}