#include <iostream>
#include <vector>
#include <cstdio>
#include <string.h>
#include <sstream>
using namespace std;

int dp[4005][4005];
int mod;

int main(){
	int n;
	mod=1e9;
	mod+=7;
	cin>>n;
	dp[1][1]=1;
	for(int i=2;i<=n;i++){
		dp[i][1]=dp[i-1][i-1];
		for(int j=2;j<=i;j++)
			dp[i][j]=(dp[i][j-1]+dp[i-1][j-1])%mod;
	}
	int res=0;
	for(int i=1;i<=n;i++)
		res=(res+dp[n][i])%mod;
	cout<<res<<"\n";
	return 0;
}