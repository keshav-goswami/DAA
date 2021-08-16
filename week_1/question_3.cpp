// Question-3) Given an already sorted array of positive integers, design an algorithm and implement it using a
// program to find whether a given key element is present in the sorted array or not. For an array
// arr[n], search at the indexes arr[0], arr[2], arr[4],.....,arr[2k] and so on. Once the interval (arr[2k]
// < key < arr[ 2k+1] ) is found, perform a linear search operation from the index 2k
// to find the element key. (Complexity < O(n), where n is the number of elements need to be scanned for searching).

#include<iostream>
#include<math.h>
using namespace std;
int c=0;
int Jump_search(int arr[],int n,int key){
    c=0;
    int jump = sqrt(n);
    int prev = 0,steps= 0;
    while(arr[int(min(steps,n)-1)]<key){
        prev = steps;
        steps+= jump;
        if(prev >= n){
            return -1;
        }
        else{
            c++;
        }
    }
    while(arr[int(prev)]<key){
        prev+=1;
        if(prev == min(steps,n)){
            return -1;
        }
        else{
            c++;
        }
    }
    if( arr[int(prev)] == key){
        c++;
        return prev;
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
        int C = Jump_search(arr,s,key);
        if(C == -1){
            cout<<"Not Present "<<c<<endl;
        }
        else{
            cout<<"Present "<<c<<endl;
        }
    }
    return 0;
}