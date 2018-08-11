#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a;
long long int mod = (1e9)+7;
unordered_map<long long int,int> freq,bidx;
long long int sz=1000000000;

void update(long long int i,int val){
    while(i<=sz)
        bidx[i]+=val,    i+= i&-i;
}

int read(long long int i){
    int ret=0;
    while(i>0)
        ret+=bidx[i],    i-= i&-i;
    return ret;
}

int main(){
	int n,ele,d;
	scanf("%d %d",&n,&d);
	for(int i=0;i<n;i++){
		scanf("%d",&ele);
		a.push_back(ele);
		update(ele,1);
	}
	int m,p,cnt,idx;
	long long int ans=1;
	for(int i=n-1;i>=0;i--){
		idx = read(a[i]+d-1)-read(a[i])+1;
		freq[a[i]]++;
		ans*=(idx+freq[a[i]]-1);
		ans%=mod;
	}
	scanf("%d",&m);
	while(m--){
		ans=1;
		scanf("%d %d",&p,&ele); p--;
		update(a[p],-1);
		a[p]=ele; 
		update(ele,1);
		freq.clear();
		for(int i=n-1;i>=0;i--){
			idx = read(a[i]+d-1)-read(a[i])+1;
			freq[a[i]]++;
			ans*=(idx+freq[a[i]]-1);
			ans%=mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}