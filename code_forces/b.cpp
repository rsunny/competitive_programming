#include <unordered_map>
#include <iostream>
#include <stdio.h>

#define SIZE 1000+10

using namespace std;

int a[SIZE],b[SIZE],c[SIZE],d[SIZE];

int main(){

    int t;cin>>t;
    int test=1;
    while(t--){
        int n,k;
        cin>>n>>k;
        long long res=0;
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int i=0;i<n;i++) scanf("%d",&b[i]);
        for(int i=0;i<n;i++) scanf("%d",&c[i]);
        for(int i=0;i<n;i++) scanf("%d",&d[i]);
        unordered_map<int,int> m1,m2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                m1[a[i]^b[j]]++;
                m2[c[i]^d[j]]++;
            }
        }
        unordered_map<int,int>::iterator it;

        for(it=m1.begin();it!=m1.end();it++){
            int val=(it->first)^k;
            if(m2[val])
                res+=(it->second)*m2[val];
        }

        printf("Case #%d: %lld\n",test++,res);
    }
    return 0;
}