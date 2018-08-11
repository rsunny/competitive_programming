#include <iostream>
#include <stack>
#include <string.h>
#include <string>

using namespace std;

int n,res;
int dp[105][105];
int rooms[105];

int doit(int bat,int cat){
	if(dp[bat][cat]!=-1)
		return dp[bat][cat];
}

int main(){
	int t;
	cin>>t;
	while(t--){
		memset(dp,-1,sizeof dp);
		res=-1;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>rooms[i];
		
		cout<<res<<"\n";
	}
	return 0;
}