#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int ep[100005];
long long int tot[100005];

int main() {
    int t,n,k,q,i,j;
    int one,zero,l,r,pos;
    long long int res;
    string s;
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        cin>>s;
        i=j=0;
        one=zero=0;
        reverse(s.begin(),s.end());
        for(;j<n;j++){
            one+=(s[j]=='1');
            zero+=(s[j]=='0');
            for(;(one>k or zero>k);i++){
                one-=(s[i]=='1');
                zero-=(s[i]=='0');
            }
            ep[n-j]=n-i;
        }
        for(i=1;i<=n;i++){
            tot[i]=tot[i-1]+ep[i]-i+1;
        }
        while(q--){
            cin>>l>>r;
            pos=lower_bound(ep+l,ep+r,r)-ep;
            res=r-pos+1;
            res*=(res+1);
            res/=2;
            res+=(tot[pos-1]-tot[l-1]);
            cout<<res<<"\n";
        }
    }
    return 0;
}
