#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

int N,M,K;
string a,b;
int dp[1009][1009][11];

int doit(int n,int m,int k){
	if(k==K or n==N or m==M)
		return 0;
	if(dp[n][m][k]!=-1)
		return dp[n][m][k];
	int res=max(doit(n+1,m,k),doit(n,m+1,k));
	int i=0;
	for(i=1;;i++){
		if(n+i==N or m+i==M or a[n+i]!=b[m+i])
			break;
	}
	if(i)
		res=max(res,doit(n+i,m+i,k+1)+i);
	dp[n][m][k]=res;
	return res;
}

int main(){
	cin>>N>>M>>K;
	cin>>a>>b;
	memset(dp,-1,sizeof dp);
	cout<<doit(0,0,0)<<"\n";
	return 0;
}
