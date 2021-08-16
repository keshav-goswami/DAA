// Question-1: Given an array of nonnegative integers, design a linear algorithm and implement it using a program to find whether a given key element is present in the array or not. Also, find the total number of comparisons for each input case. (Time Complexity = O(n), where n is the size of input).

#include<iostream>
using namespace std;
int Linear_search(int arr[],int size,int key){
    int ans = -1;
    for(int i=0;i<size;i++){
        if(arr[i] == key){
            return i+1;
        }
    }
    return ans;
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
        int Index = Linear_search(arr,s,key);
        if(Index == -1){
            cout<<"Not Present "<<s+1<<endl;
        }
        else{
            cout<<"Present "<<Index<<endl;
        }
    }
    return 0;
}