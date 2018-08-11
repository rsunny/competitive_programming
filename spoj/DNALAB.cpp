#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int dp[1<<16][16];
int wt[20][20];
int n;
set<string> arr;
vector<string> a;
string s;

int doit(int mask,int pos){
  if(mask==(1<<n)-1){
    dp[mask][pos]=0;
    return 0;
  }
  if(dp[mask][pos]!=-1)
    return dp[mask][pos];
  int res=1e9;
  for(int i=0;i<n;i++){
    if((mask&(1<<i))==0)
      res=min(res,doit(mask|1<<i,i)+wt[pos][i]);
  }
  dp[mask][pos]=res;
  return res;
}

void dfs(int mask,int pos){
  if(mask==(1<<n)-1)
    return ;
  string temp="Z";
  int p=-1;
  for(int i=0;i<n;i++){
    string ss=a[i].substr(a[i].size()-wt[pos][i]);
    if((mask&(1<<i))==0 and dp[mask|1<<i][i]==dp[mask][pos]-wt[pos][i] and temp>ss){
      temp=ss;
      p=i;
    }
  }
  s+=temp;
  dfs(mask|(1<<p),p);
  return ;
}

int main(){
  int t;
  int test=1;
  scanf("%d",&t);
  while(t--){
    memset(dp,-1,sizeof dp);
    arr.clear();
    a.clear();
    scanf("%d",&n);
    for(int i=0;i<n;i++)
      cin>>s,arr.insert(s);
    set<string> ::iterator it,jt;
    for(it=arr.begin();it!=arr.end();it++){
      for(jt=arr.begin();jt!=arr.end();jt++){
        s=*jt;
        if(it!=jt and s.find(*it)!=-1)
          goto here;
      }
      a.push_back(*it);
      here: ;
    }
    n=a.size();
    sort(a.begin(), a.end());
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        for (int l=0; l<=min(a[i].size(),a[j].size());l++) 
          if (a[i].substr((int)a[i].size() - l) == a[j].substr(0, l)) 
            wt[i][j] = (int)a[j].size() - l;
    int res=1e9;
    for(int i=0;i<n;i++){
      res=min(res,doit(1<<i,i)+(int)a[i].size());
    }
    string temp="Z";
    int pos=-1;
    for(int i=0;i<n;i++){
      if(dp[1<<i][i]==res-a[i].size() and temp>a[i]){
        pos=i;
        temp=a[i];
      }
    }
    s=temp;
    dfs(1<<pos,pos);
    cout<<"Scenario #"<<test++<<":\n";
    cout<<s<<"\n\n";
  }
  return 0;
}
