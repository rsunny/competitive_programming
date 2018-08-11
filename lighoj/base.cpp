#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#include <string.h>

using namespace std;

string s;
int b,k,n;
long long int dp[1<<16][20];
map<char,int> val;

long long int doit(int mask, int mod){
  if((mask+1)==(1<<n))
    return (mod==0);
  if(dp[mask][mod]!=-1)
    return dp[mask][mod];
  long long int res=0;
  for(int i=0;i<n;i++){
    if(mask&(1<<i))
      continue;
    res+=doit(mask|(1<<i),(mod*b+val[s[i]])%k);
  }
  dp[mask][mod]=res;
  return res;
}

int main(){
  int t;
  cin>>t;
  val['0']=0; val['1']=1; val['2']=2; val['3']=3; val['4']=4; val['5']=5; val['6']=6; val['7']=7; val['8']=8;
  val['9']=9; val['A']=10; val['B']=11; val['C']=12; val['D']=13; val['E']=14; val['F']=15;
  for(int T=1;T<=t;T++){
    cin>>b>>k;
    cin>>s; n=s.size();
    memset(dp,-1,sizeof dp);
    printf("Case %d: ",T);
    cout<<doit(0,0)<<"\n";
  }
  return 0;
}