#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int arr[100005];

int main() {
    int n,m,k,l,r,res;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    while(k--){
        unordered_map<int,int> fir;
        res=0;
        cin>>l>>r;
        for(int i=l;i<=r;i++){
            if(!fir[arr[i]])
                fir[arr[i]]=i;
            res=max(res,i-fir[arr[i]]);
        }
        cout<<res<<"\n";
    }
    return 0;
}
