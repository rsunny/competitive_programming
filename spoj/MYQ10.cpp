#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

int dp[25][3];

int doit(int pos,int num){
	if(pos==25)
		return 1;
	if(dp[pos][num]!=-1)
		return dp[pos][num];
	int res=0;
	res+=doit(pos,0);
	res+=doit(pos,1);
	res+=doit(pos,8);
	dp[pos][num]=res;
	return res;
}

int check(string num){
	
}

int main(){
	memset(dp,-1,sizeof dp);
	doit(0,0);
	int t;
	cin>>t;
	while(t--){
		string a,b;
		cin>>a>>b;
		int res = check(b)-check(a);
		cout<<res<<"\n";
	}
	return 0;
}
