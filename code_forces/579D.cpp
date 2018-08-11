#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

long long int dp[200005][15];
int n,k;
long long int x;
long long int arr[200005];
long long int powx[15];

long long int doit(int id,int rem){
	if(id==n)
		return 0;
	if(dp[id][rem]!=-1)
		return dp[id][rem];
	long long int res=0;
	for(int i=0;i<=rem;i++){
		res=max(res,doit(id+1,rem-i)|(arr[id]*powx[i]));
	}
	dp[id][rem]=res;
	return res;
}

int main(){
	cin>>n>>k>>x;	
	powx[0]=1;
	for(int i=1;i<=k;i++)
		powx[i]=powx[i-1]*x;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=k+2;j++)
			dp[i][j]=-1;
	cout<<doit(0,k)<<"\n";
	return 0;
}