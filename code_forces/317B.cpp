#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
//#include <bits/stdc++.h>

using namespace std;

const int maxn = (3 * 1e5) + 9;
long long int maxv=1e17;
long long int arr[maxn];
vector<long long int> v;
int n,k,sz;
long long int dp[5005][5005];

long long int doit(int l,int s){
	if(l+s>k)
		return 0;
	if(dp[l][s]!=-1)
		return dp[l][s];
	int pos = (l*(sz+1))+(s*sz);
	long long int res1=maxv,res2=maxv;
	if(pos+sz<n and doit(l,s+1)!=maxv)
		res1=doit(l,s+1)+v[pos+sz]-v[pos];
	if(pos+sz+1<n and doit(l+1,s)!=maxv)
		res2=doit(l+1,s)+v[pos+sz+1]-v[pos];
	dp[l][s]=min(res1,res2);
	return dp[l][s];
}

int main(int argc, char *argv[]){
	cin>>n>>k;
	sz=n/k;
	for(int i=1;i<=n;i++)
		cin>>arr[i],v.push_back(arr[i]);
	
	sort(v.begin(), v.end());
	memset(dp,-1,sizeof dp);
	cout<<doit(0,0)<<"\n";
	return 0;
}
