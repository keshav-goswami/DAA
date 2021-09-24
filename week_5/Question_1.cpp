// 1. Given an unsorted array of alphabets containing duplicate elements. Design an algorithm and implement it using a program to find which alphabet has maximum number of occurrences and print it. (Time Complexity = O(n)) (Hint: Use counting sort).

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T; 
    while (T--) 
    {
        string s;
        int n, t, mx = -999;
        cin>>n;
        cin>>s;
        vector<int> Cnt(26);
        for(int i = 0;i < s.length();i++)
        {
            Cnt[s[i]-'a']++;
        } 
        for (int i = 0; i < s.length(); i++)
        {
            if(mx<Cnt[i]) mx = Cnt[i];
        }
        for (int i = 0; i < Cnt.size(); i++)
        {
            if (Cnt[i] == mx && mx != 1)   
            {
                char c = i+'a';  
                cout << c <<"-"<<Cnt[i]<<endl; 
                break; 
            }
            else if(mx == 1){
                cout<<"No Duplicates Found"<<endl;
                break;
            }
        }
    }
    return 0;
}