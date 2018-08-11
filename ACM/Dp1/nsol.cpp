#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <cassert>

using namespace std;

#define MAXN (1<<22)

int n,m,q,cnt,am;
int f[35],s[35]; 
long long int st[25][25];
long long int dp[25][MAXN+10];
long long int bad[25];
int comp[(1<<24)+10];
long long int temp;

void pre(){
	for(int i=0;i<=(1<<24);i++)
		if(__builtin_popcount(i)%4==0)
			comp[i]=cnt,cnt++;
}

long long int doit(int sg,int mask){
	assert(comp[mask]>=1 and comp[mask]<=(1<<22));
	assert(mask>=0 and mask<=(1<<24));
	long long int res=0;
	if(sg==m or __builtin_popcount(mask)==am){
		for(int i=0;i<n;i++)
			if((mask&(1<<i))==0)
				res-=bad[i];
		return res;
	}
	if(dp[sg][comp[mask]]!=-1)
		return dp[sg][comp[mask]];

	res=doit(sg+1,mask);
	for(int i=1;i<=q;i++){
		if(!(mask&(1<<f[i])) and !(mask&(1<<s[i]))){
			for(int j=i+1;j<=q;j++){
				if(!(mask&(1<<f[j])) and !(mask&(1<<s[j])) and f[i]!=f[j] and f[i]!=s[j] and s[i]!=f[j] and s[i]!=s[j]){
					temp=doit(sg+1,mask|(1<<f[i])|(1<<f[j])|(1<<s[i])|(1<<s[j]));
					temp+=(max(st[sg+1][f[i]],st[sg+1][s[i]])*max(st[sg+1][f[j]],st[sg+1][s[j]]));
					res=max(res,temp);
				}
			}
		}
	}
	
	dp[sg][comp[mask]]=res;
	return res;
}

int main(){
	cnt=1,pre();
	scanf("%d %d",&m,&n);
	scanf("%d",&q);
	assert(n>=1 and n<=24 and m>=1 and m<=20 and q>=1 and q<=30);
	am=(n/4)*4;

	for(int j=0;j<n;j++)
		scanf("%lld",&bad[j]),assert(bad[j]>=1 and bad[j]<=(int)1e6);

	for(int i=1;i<=m;i++)
		for(int j=0;j<n;j++)
			scanf("%lld",&st[i][j]),assert(st[i][j]>=1 and st[i][j]<=(int)1e6);

	for(int i=1;i<=q;i++)
		scanf("%d %d",&f[i],&s[i]),assert(f[i]>=1 and f[i]<=n),assert(s[i]>=1 and s[i]<=n),f[i]--,s[i]--;

	memset(dp,-1,sizeof dp);
	printf("%lld\n",doit(0,0));
	return 0;
}