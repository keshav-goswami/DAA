// III. Given an unsorted array of integers, design an algorithm and implement it using a program to find Kth smallest or largest element in the array. (Worst case Time Complexity = O(n))

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        vector<int> v;
        int n, t, mx = -999, sum = 0, mn = 999;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> t;
            if (t > mx)
                mx = t; 
            if (t < mn)
                mn = t;
            v.push_back(t);
        }
        int K;
        cin >> K;
        vector<int> Cnt(mx + 1);
        for (int i = 0; i < n; i++)
        {
            if (mn <= v[i])
                Cnt[v[i]]++;
        }
        for (int i = 0; i < Cnt.size(); i++)
        {
            sum += Cnt[i];
            if (sum >= K)
            {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}