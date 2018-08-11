#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 2 * (1e5) + 100;

int t,n,res;
string s[2];
int dp[2][maxn];

int doit(){
  dp[1][0]=(s[1][0]=='.')?0:1e9;
  dp[0][0]=(s[0][0]=='.')?0:1e9;
  for(int i=1;i<n;i++){
    if(dp[0][i-1]!=1e9){
      if(s[0][i]=='.') dp[0][i]=min(dp[0][i],dp[0][i-1]);
      if(s[1][i-1]=='.') dp[1][i-1]=min(dp[1][i-1],dp[0][i-1]+1);
      if(s[1][i]=='.') dp[1][i]=min(dp[1][i],dp[0][i-1]+1);
    }
    if(dp[1][i-1]!=1e9){
      if(s[1][i]=='.') dp[1][i]=min(dp[1][i],dp[1][i-1]);
      if(s[0][i-1]=='.') dp[0][i-1]=min(dp[0][i-1],dp[1][i-1]+1);
      if(s[0][i]=='.') dp[0][i]=min(dp[0][i],dp[1][i-1]+1);
    }
  }
  if(dp[1][n-1]!=-1 and dp[0][n-1]!=-1)
    return min(dp[0][n-1],dp[1][n-1]);
  return max(dp[0][n-1],dp[1][n-1]);
}

int main(){
    scanf("%d",&t);
    while(t--){
      cin>>s[0]>>s[1];
      n=s[0].size();
      for(int i=0;i<n;i++)
        dp[1][i]=dp[0][i]=1e9;
      res=doit();
      if(res!=1e9)
        printf("Yes\n%d\n",res);
      else
        printf("No\n");
    }
    return 0;
}
