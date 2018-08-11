#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

long long int dp[105][105][105];
long long int p[105][105];
int clr[105];
int n,k,m;
long long int inv;

long long int doit(int pos,int grp,int c){
	if(grp>k)
		return inv;
	if(pos==n)
		return (grp==k?0:inv);
	if(dp[pos][grp][c]!=-1)
		return dp[pos][grp][c];
	long long int res=inv;
	if(clr[pos]!=m){
		res=doit(pos+1,grp+(clr[pos]!=c),clr[pos]);
	}
	for(int i=0;clr[pos]==m and i<m;i++){
		res=min(res,p[pos][i]+doit(pos+1,grp+(c!=i),i));
	}
	dp[pos][grp][c]=res;
	return res;
}

int main(){
	cin>>n>>m>>k;
	inv=1LL;
	
	for(int i=0;i<15;i++)
		inv*=(10LL);
	
	for(int i=0;i<n;i++){
		cin>>clr[i],clr[i]--;
		if(clr[i]==-1)
			clr[i]=m;
	}

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>p[i][j];

	for(int i=0;i<105;i++)
		for(int j=0;j<105;j++)
			for(int k=0;k<105;k++)
				dp[i][j][k]=-1;

	long long int res=doit(0,0,m+1);
	if(res==inv)
		cout<<"-1\n";
	else
		cout<<res<<"\n";
	return 0;
}
