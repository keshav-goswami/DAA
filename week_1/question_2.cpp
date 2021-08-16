// Question-2)Given an already sorted array of positive integers, design an algorithm and implement it using a
// program to find whether given key element is present in the array or not. Also, find total number
// of comparisons for each input case. (Time Complexity = O(nlogn), where n is the size of input).

#include<iostream>
using namespace std;
int Binary_search(int arr[],int l,int r,int key){
    int c=0;
    while(l<r){
        int mid = l + (r-l)/2;
        if(arr[mid] == key){
            return c;
        }
        else if(arr[mid] < key){
            c++; 
            l = mid+1;
        }
        else if(arr[mid] > key){
            c++;
            r = mid-1;
        }
    }
    return -1;
}
int main(){
    int t,s,key;
    cin>>t;
    while(t--){
        cin>>s;
        int arr[s]; 
        for(int i=0;i<s;i++){  
            cin>>arr[i];
        }
        cin>>key;
        int C = Binary_search(arr,0,s,key);
        if(C == -1){
            cout<<"Not Present "<<C<<endl;
        }
        else{
            cout<<"Present "<<C+1<<endl;
        }
    }
    return 0;
}