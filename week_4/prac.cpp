#include<iostream>
#include <iomanip>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){ 
        double n;
        cin>>n;
        double sum = 0;
        for(double i=1;i<=n;i++){  
            sum+=i;
        }
        cout<<sum/n<<endl;  
    }
    return 0;
}