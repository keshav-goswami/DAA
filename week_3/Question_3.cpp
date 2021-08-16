// III. Given an unsorted array of positive integers, design an algorithm and implement it using a program to find whether there are any duplicate elements in the array or not. (use sorting) (Time Complexity = O(n log n)).

#include <iostream>
using namespace std;
int binary_search_first(int arr[], int start, int end, int key)
{
    if (end >= start)
    {
        int mid = start + (end - start) / 2;
        if ((mid == 0 || key > arr[mid - 1]) && arr[mid] == key)
            return mid;
        else if (key > arr[mid])
            return binary_search_first(arr, (mid + 1), end, key);
        else
            return binary_search_first(arr, start, (mid - 1), key);
    }
    return -1;
}
int binary_search_last(int arr[], int start, int end, int key, int n)
{
    if (end >= start)
    {
        int mid = start + (end - start) / 2;
        if ((mid == n - 1 || key < arr[mid + 1]) && arr[mid] == key)
            return mid;
        else if (key < arr[mid])
            return binary_search_last(arr, start, (mid - 1), key, n);
        else
            return binary_search_last(arr, (mid + 1), end, key, n);
    }
    return -1;
}
void merge(int arr[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = p;
    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        bool flag = true;
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        // Sorting using Merge Sort O(nlogn)
        mergeSort(arr, 0, n - 1);
        // searching element count of every element of array using Binary Search O(nlogn)
        for(int i=0;i<n;i++){
            int first = binary_search_first(arr, 0, n - 1,arr[i]);
            int last = binary_search_last(arr, 0, n - 1,arr[i],n);
            if(first!=last){
                cout<<"YES";
                flag = false;
                break;
            }
        }
        if(flag){
            cout<<"NO";
        }
        cout<<endl;
    }
    return 0;
}