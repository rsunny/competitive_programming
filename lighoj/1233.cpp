#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

const int mod = 100000007;

int n,k;
int arr[109];
int cst[109];
bool  dp[100009];
int freq[100009];

int main(){
	int t;
	freopen("input.txt","r",stdin);
	scanf("%d",&t);
	for(int test=1;test<=t;test++){
		memset(dp,false,sizeof dp);
		printf("Case %d: ",test);
		scanf("%d %d",&n,&k);
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		for(int i=0;i<n;i++)
			scanf("%d",&cst[i]);
		dp[0]=true;
		for(int i=0;i<n;i++){
			for(int j=0;j<=k;j++)
				freq[j]=0;
			for(int j=0;j<=k;j++){
				if(j+arr[i]>k)
					break;
				if(dp[j] and !dp[j+arr[i]] and freq[j]<cst[i]){ 
					dp[j+arr[i]]=true;
					freq[j+arr[i]]=freq[j]+1;
				}
			}
		}
		int res=0;
		for(int i=1;i<=k;i++)
			if(dp[i])
				res++;
		printf("%d\n",res);
	}
	return 0;
}
