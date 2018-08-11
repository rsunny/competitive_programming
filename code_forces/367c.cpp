#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

long long int dp[100005][3];
vector<string> v[2];
vector<long long int> s[2];
int n;
long long int inf=100000000000000000;

long long int doit(int pos,int r){
	if(pos==n-1)
		return s[r][pos];
	if(dp[pos][r]!=-1)
		return dp[pos][r];
	long long int res = inf;
	if(v[r][pos]<=v[0][pos+1])
		res = s[r][pos]+doit(pos+1,0);
	if(v[r][pos]<=v[1][pos+1])
		res = min(res,doit(pos+1,1)+s[r][pos]);
	dp[pos][r]=res;
	return res;
}

int main(){
	cin>>n;
	string temp;
	long long int e;
	for(int i=0;i<n;i++)
		cin>>e,s[1].push_back(e),s[0].push_back(0);
	for(int i=0;i<n;i++){
		cin>>temp;
		v[0].push_back(temp);
		reverse(temp.begin(),temp.end());
		v[1].push_back(temp);
	}
	memset(dp,-1,sizeof dp);
	long long int res=min(doit(0,0),doit(0,1));
	if(res==inf)
		res=-1;
	cout<<res<<"\n";
	return 0;
}
