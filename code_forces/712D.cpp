#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <map>
using namespace std;

map<int,int> m;
map<int,int> freq;
map<int,int> dp[105],vis[105];
int mod = (1e9)+7;

int a,b,k,t;

int doit(int diff,int step){
	if(step==t)
		return diff>0;
	if(vis[diff][step])
		return dp[diff][step];
	vis[diff][step]=1;
	int lo=hi=2*k;lo*=-1;
	while(lo<hi){
		int mid=lo+hi;
		mid/=2;
		if()
	}
	dp[diff][step]=res;
	return res;
}

int main(){
	cin>>a>>b>>k>>t;
	for(int i=-k;i<=k;i++){
		for(int j=-k;j<=k;j++){
			m[i-j]++;
		}
	}
	
	map<int,int> :: iterator it;
	for(it=m.begin();it!=m.end();it++)
		freq[(it->first)]=(it->second)+freq[(it->first)-1];

	cout<<doit(a-b,0)<<"\n";
	return 0;
}
