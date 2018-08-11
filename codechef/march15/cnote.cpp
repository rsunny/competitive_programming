#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t,x,y,k,n,p,c;
    bool pre;
    string yes="LuckyChef\n";
    string no="UnluckyChef\n";
    cin>>t;
    while(t--){
        pre=false;
        cin>>x>>y>>k>>n;
        for(int i=0;i<n;i++){
            cin>>p>>c;
            pre|=(p>=(x-y) && k>=c);
        }
        pre?cout<<yes:cout<<no;
    }
    return 0;
}
