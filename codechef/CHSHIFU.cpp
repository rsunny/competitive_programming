#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

int neigh[25];

int main(){
	int t;
	scanf("%d",&t);
	for(int test=1;test<=t;test++){
		int n,m;
		cin>>n>>m;
		for(int i=0;i<=n;i++)
			neigh[i]=1<<i;
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			a--,b--;
			neigh[a]|=1<<b;
			neigh[b]|=1<<a;
		}
		int mask,cnt;
		int res=100;
		int lmt=(1<<n);lmt--;
		for(int i=0;i<=lmt;i++){
			mask=0,cnt=0;
			for(int j=0;j<n;j++)
				if(i&(1<<j))
					mask|=neigh[j],cnt++;
			if(mask==lmt)
				res=min(res,cnt);
		}
		cout<<res<<"\n";
	}
	return 0;
}
