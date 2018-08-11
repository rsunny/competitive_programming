#include <iostream>
#include <unordered_map>
#include <set>
#include <bitset>
#include <stdio.h>

using namespace std;

unordered_map<long long int,int> vis,dp;
string per1="Henry";
string per2="Derek";

int doit(long long int num){
    long long int n=1;
    int pos=1;
    long long int arr[4]={6,1,2,4};
    while(n<=num){
        arr[pos]*=12LL;
        n=arr[(pos+1)%4];
        if(n<=num)
            pos++,pos%=4;
    }
    return pos;
}

int main(){
    int t,n,w;
    long long int num;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        w=0;
        for(int i=1;i<=n;i++){
            scanf("%lld",&num);
            w^=doit(num);
        }
        cout<<(w?per1:per2)<<"\n";
    }
    return 0;
}