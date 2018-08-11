#include <iostream>
#include <unordered_map>
#include <set>
#include <bitset>
#include <stdio.h>

using namespace std;

unordered_map<long long int,int> vis,dp;
string per1="Henry";
string per2="Derek";

bool doit(long long int num){
    if(num==0)
        return 0;
    if(vis[num])
        return dp[num];
    vis[num]=true;
    bitset<100> res;
    int ret=0;
    for(int i=2;i<=6;i++)
        res.set(doit(num/i));
    while(res.test(ret))
        ret++;
    dp[num]=ret;
    return ret;
}

int main(){
    int t,n,w;
    long long int num;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        w=0;
        for(int i=0;i<n;i++){
            scanf("%lld",&num);
            cout<<doit(num)<<"\n";
            w^=doit(num);
        }
        cout<<(w?per2:per1)<<"\n";
    }
    return 0;
}