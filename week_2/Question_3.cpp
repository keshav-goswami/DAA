// III. Given an array of nonnegative integers, design an algorithm and a program to count the number
// of pairs of integers such that their difference is equal to a given key, K. 

#include<iostream>
using namespace std;
int count(int arr[], int n, int k)
{
    int C = 0;

    for (int i = 0; i < n; i++)
    {      
        for (int j = i+1; j < n; j++){
            if (arr[i] - arr[j] == k || arr[j] - arr[i] == k )
                  C++;
        }
    }
    return C;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        int key;
        cin>>key;
        cout<<count(a,n,key)<<endl;
    }
    return 0;
}