#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int mod[1005];
int val[1005];
int dp[1005][1005];
int n,m;

string yes="YES";
string no="NO";

int doit(int ind,int sum){
	if(ind==m)
		return (sum==0);
	if(dp[ind][sum]!=-1)
		return dp[ind][sum];
	int res=0;
	if(val[ind])
		res|=doit(ind+1,(sum+ind)%m);
	res|=doit(ind+1,sum);
	dp[ind][sum]=res;
	return res;
}

int main(){
	int temp;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		temp%=m;
		mod[temp]++;
		val[(mod[temp]*temp)%m]=1;
	}
	memset(dp,-1,sizeof dp);
	string res=yes;
	if(!doit(0,0))
		res=no;
	cout<<res<<"\n";
	return 0;
}