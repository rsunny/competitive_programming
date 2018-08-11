#include <iostream>
#include <math.h>
#include <string.h>
#include <stdio.h>

using namespace std;

int M, N;

double dp[100005];
bool vis[100005];

float doit(int n) {
  if(n==1)
    return 0;
  if(vis[n])
    return dp[n];
  int m = sqrt(n + 1);
  double res = 0;
  int div = 2;
  
  for (int i = 2; i <= m; i++) {
    if (n % i == 0) {
      res += doit(n/i);
      div++;
      if (i != n/i) {
        res += doit(i);
        div++;
      }
    }
  }
  
  res+=div;
  res/=(div-1);
  
  vis[n]=true;
  dp[n] = res;
  return dp[n];
}

int main(){
  memset(dp,-1,sizeof dp);
  dp[1] = 0;
  int t,ct=1;
  cin>>t;
  while(t--){
    scanf("%d", &N);
    printf ("Case %d: %.6f\n", ct,doit(N));
    ct++;
  }
  return 0;
}