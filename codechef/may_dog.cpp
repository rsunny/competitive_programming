#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

#define MOD 1000000007

int dp[1009][1009];
int vis[1009][1009];
int arr[1009];
int n,m,s;
queue<int> pos,step;
int qp,qs;

int main(){
	int t;
	cin>>t;
	while(t--){
		memset(dp,0,sizeof dp);
		memset(vis,0,sizeof vis);
		cin>>n>>m>>s;
		for(int i=0;i<m;i++)
			cin>>arr[i];
		pos.push(s);
		step.push(0);
		dp[s][0]=1;
		while(pos.size()){
			qp=pos.front(), qs=step.front();
			pos.pop(), step.pop();
			if(qs==m)
				continue;
			if(qp+arr[qs]>=1 and qp+arr[qs]<=n){
				dp[qp+arr[qs]][qs+1]=(dp[qp+arr[qs]][qs+1]+dp[qp][qs])%MOD;
				if(!vis[qp+arr[qs]][qs+1])
					pos.push(qp+arr[qs]),step.push(qs+1),vis[qp+arr[qs]][qs+1]=true;
			}
			if(qp-arr[qs]>=1 and qp-arr[qs]<=n){
				dp[qp-arr[qs]][qs+1]=(dp[qp-arr[qs]][qs+1]+dp[qp][qs])%MOD;
				if(!vis[qp-arr[qs]][qs+1])
					pos.push(qp-arr[qs]),step.push(qs+1),vis[qp-arr[qs]][qs+1]=true;
			}
		}
		for(int i=1;i<=n;i++)
			cout<<dp[i][m]<<" ";
		cout<<"\n";
	}
	return 0;
}