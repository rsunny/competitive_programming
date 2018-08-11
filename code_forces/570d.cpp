#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

#define MAXN (1<<19)

long long int bef[20][20];
int n,m,k,x,y;
long long c;
long long int sat[20];
int ones[MAXN];
long long int dp[MAXN][20];

long long int doit(int mask,int l){
	if(ones[mask]==m)
		return 0;
	
	if(dp[mask][l]!=-1)
		return dp[mask][l];

	long long int res=0;
	for(int i=1;i<=n;i++){
		if(!(mask&(1<<i))){
			res=max(res,doit(mask|(1<<i),i)+sat[i]+bef[l][i]);
		}
	}
	dp[mask][l]=res;
	return res;
}

int main(){
	for(int i=0;i<MAXN;i++){
		int temp=i,cnt=0;
		while(temp)
			cnt+=temp%2,temp/=2;
		ones[i]=cnt;
	}
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>sat[i];
	for(int i=0;i<k;i++){
		cin>>x>>y>>c;
		bef[x][y]=max(bef[x][y],c);
	}

	memset(dp, -1, sizeof dp);

	long long int res=0;
	for(int i=1;i<=n;i++){
		res=max(res,doit((1<<i),i)+sat[i]);
	}
	cout<<res<<"\n";
	return 0;
}