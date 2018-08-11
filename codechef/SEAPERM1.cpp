#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a,b;
long long int mod = (1e9)+7;
int max_ele=-1;

int main(){
	int n,ele,d;
	scanf("%d %d",&n,&d);
	for(int i=0;i<n;i++){
		scanf("%d",&ele);
		a.push_back(ele);
		b.push_back(ele);
		max_ele=max(max_ele,ele);
	}
	sort(b.begin(), b.end());
	int m,p,cnt,idx;
	long long int ans=1;
	for(int i=n-1;i>=0;i--){
		idx = (upper_bound(b.begin(), b.end(), min(b[i]+d-1,b[n-1])) - b.begin())-i;
		ans*=idx;
		ans%=mod;
	}
	scanf("%d",&m);
	while(m--){
		ans=1;
		scanf("%d %d",&p,&ele); p--;
		a[p]=ele; 
		b.clear();
		for(int i=0;i<n;i++){
			b.push_back(a[i]);
		}
		sort(b.begin(), b.end());
		for(int i=n-1;i>=0;i--){
			idx = (upper_bound(b.begin(), b.end(), min(b[i]+d-1,b[n-1])) - b.begin())-i;
			cout<<b[i]<<" "<<idx<<"\n";
			ans*=idx;
			ans%=mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}