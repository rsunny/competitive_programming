#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

int n;
int arr[109];
int dp[109][59];

int main(){
	int t;
	scanf("%d",&t);
	for(int test=1;test<=t;test++){
		memset(dp,-1,sizeof dp);
		printf("Case %d: ",test);
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		printf("%d\n",doit(0,0));
	}
	return 0;
}
