#include <iostream>
#include <string.h>
#include <cassert>
#include <algorithm>

using namespace std;

int dp[105][105][105];
int arr[105];
int n;

int doit(int pos,int bat,int cat){
	if(pos==n)
		return 0;
	if(dp[pos][bat][cat]!=-1)
		return dp[pos][bat][cat];
	int res=0;
	res=doit(pos+1,bat,cat);
	if(bat>arr[pos])
		res=max(res,doit(pos+1,arr[pos],cat)+1);
	if(cat<arr[pos])
		res=max(res,doit(pos+1,bat,arr[pos])+1);
	dp[pos][bat][cat]=res;
	return res;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		memset(dp,-1,sizeof dp);
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>arr[i];
		cout<<doit(0,101,-1)<<"\n";
	}
	return 0;
}