#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <cstdio>

using namespace std;

long long int dp[5000005];
long long int sum[5000005];

int main(){
	for(int i=2;i<=5000000;i++){
		for(int j=1;(j*i)<=5000000;j++){
			dp[i*j]=max(dp[j]+1,dp[i*j]);
		}
	}
	sum[1]=0;
	for(int i=2;i<=5000000;i++)
		sum[i]=sum[i-1]+dp[i];
	int test;
	scanf("%d",&test);
	while(test--){
		int a,b;
		scanf("%d %d",&a,&b);
		long long int res=sum[a]-sum[b];
		printf("%I64d\n",res);
	}
	return 0;
}