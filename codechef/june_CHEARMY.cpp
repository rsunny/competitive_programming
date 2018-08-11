#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

long long int dp[13][20];
string s;

long long int doit(int num,int pos){
	if(pos==0){
		dp[num][pos]=1;
		return 1LL;
	}
	if(dp[num][pos]!=-1)
		return dp[num][pos];
	long long int res=0;
	for(int i=0;i<10;i+=2)
		res+=doit(i,pos-1);
	dp[num][pos]=res;
	return res;
}

void dfs(long long int k,int pos){
	if(pos==-1)
		return;
	long long int sum=0;
	for(int i=0;i<10;i+=2){
		if(sum+dp[i][pos]>=k){
			s+=(char)('0'+i);
			dfs(k-sum,pos-1);
			break;
		}
		sum+=dp[i][pos];
	}
	return ;
}	

int main(){
	for(int i=0;i<13;i++)
		for(int j=0;j<20;j++)
			dp[i][j]=-1;
	doit(0,18);
	int t;
	scanf("%d",&t);
	for(int test=1;test<=t;test++){
		long long int k;
		scanf("%lld",&k);
		s="";
		dfs(k,18);
		int d=0;
		for(int i=0;i<(int)s.size();i++){
			if(s[i]!='0')
				d=1;
			if(d)
				cout<<s[i];
		}
		if(d==0)
			cout<<"0";
		cout<<"\n";
	}
	return 0;
}
