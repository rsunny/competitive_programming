#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

const int mod = 100000007;

int n,k;
int arr[109];
int dp[10009];
int freq[10009];

int main(){
	int t;
	freopen("input.txt","r",stdin);
	scanf("%d",&t);
	for(int test=1;test<=t;test++){
		memset(dp,0,sizeof dp);
		printf("Case %d: ",test);
		scanf("%d %d",&n,&k);
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		dp[0]=1;
		for(int i=0;i<n;i++){
			for(int j=0;j<=k;j++)
				freq[j]=0;
			for(int j=0;j<=k;j++){
				if(j+arr[i]>k)
					break;
				if(dp[j] and freq[j]<k){ 
					dp[j+arr[i]]+=dp[j];
					dp[j+arr[i]]%=mod;
					freq[j+arr[i]]=freq[j]+1;
				}
			}
		}
		printf("%d\n",dp[k]);
	}
	return 0;
}
