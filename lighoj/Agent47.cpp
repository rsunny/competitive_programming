#include <iostream>
#include <string.h>

using namespace std;

int n;
int wep[20][20];
int hlt[20];
int dp[1<<16];

int doit(int mask){
	if(mask==(1<<n)-1)
		return 0;
	if(dp[mask]!=-1)
		return dp[mask];
	int ret=1e9;
	for(int j=0;j<n;j++){
		if(mask&(1<<j))
			continue;
		int w=1;
		for(int i=0;i<n;i++){
			if(mask&(1<<i))
				w=max(w,wep[i][j]);
		}
		ret=min(doit(mask|(1<<j))+(hlt[j]/w)+((hlt[j]%w)!=0),ret);
	}
	dp[mask]=ret;
	return ret;
}

int main(){
	int t,test=0;
	cin>>t;
	while(t--){
		test++;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>hlt[i];
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			for(int j=0;j<n;j++)
				wep[i][j]=s[j]-'0';
		}
		memset(dp,-1,sizeof dp);
		cout<<"Case "<<test<<": "<<doit(0)<<"\n";
	}
	return 0;
}