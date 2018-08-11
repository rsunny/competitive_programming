#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

int dp[1005][1005][2];
bool vis[1005][1005][2];
int n[2],m[2];
string s[2],rs[2];
unordered_map<char,bool> mid;
int num;
bool present;

int doit(int l,int r){
  if(l==n[num] or r==n[num])
    return 0;

  if(dp[l][r][num]!=-1)
    return dp[l][r][num];
 
  int res ;
  res = doit(l+1,r+1)+(s[num][l]==rs[num][r]);
  res = max(res,max(doit(l+1,r),doit(l,r+1)));
  dp[l][r][num]=res;

  return res;
}

void dfs(int l,int r){
  if(l==n[num] or r==n[num])
    return;
  int res = dp[l][r][num];
  vis[l][r][num] = true;
  if(res==m[num] and (l+r)==n[num]-1){
    if(num==0)
      mid[s[num][l]] = true;
    else if(num==1 and mid[s[num][l]])
      present=true;
    return ;
  }
  if(!vis[l+1][r+1][num]) dfs(l+1,r+1);
  if(!vis[l+1][r][num])   dfs(l+1,r);
  if(!vis[l][r+1][num])   dfs(l,r+1);
  return ;
}

int main() {
  int t;
  cin>>t;
  while(t--){
    present=false;
    mid.clear();
    memset(m,-1,sizeof m);
    
    cin>>s[0]; n[0]=s[0].size();
    cin>>s[1]; n[1]=s[1].size();

    rs[0]=s[0];
    reverse(rs[0].begin(), rs[0].end());
    rs[1]=s[1];
    reverse(rs[1].begin(), rs[1].end());
    
    memset(dp,-1,sizeof dp);
    num=0, m[num]=doit(0,0);
    num=1, m[num]=doit(0,0);

    int ans = m[0]+m[1];
    
    if(m[0]%2==1 and m[1]%2==1){   
      memset(vis,false,sizeof vis); 
      m[0] = (m[0]+1)/2, num=0, dfs(0,0);
      m[1] = (m[1]+1)/2, num=1, dfs(0,0);
      ans -= (present^1);
    }

    cout<<ans<<"\n"; 
  }
  return 0;
}
