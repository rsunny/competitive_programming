#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int t,n,l,r,a,b,c,st;
vector<int> edge[100100],dist[100100];
vector<int> path;
set<pair<int,int> > vis;

void dfs(int par,int node,int len,int mini){
  cout<<st<<" "<<node<<" "<<len<<" "<<mini<<"\n";
  if(len>=l and len<=r and vis.find(make_pair(min(st,node),max(st,node)))!=vis.end())
    path.push_back(mini),vis.insert(make_pair(min(st,node),max(st,node)));
  for(int i=0;i<edge[node].size();i++){
    if(par==edge[node][i])
      continue;
    dfs(node,edge[node][i],len+1,min(mini,dist[node][i]));
  }
  return ;
}

int main(){
    scanf("%d",&t);
    while(t--){
      scanf("%d %d %d",&n,&l,&r);
      for(int i=0;i<n-1;i++){
        scanf("%d %d %d",&a,&b,&c);
        edge[a].push_back(b); edge[b].push_back(a);
        dist[a].push_back(c); dist[b].push_back(c);
      }
      for(int i=1;i<=n;i++)
        st=i,dfs(0,i,0,INT_MAX);
      sort(path.begin(), path.end());
      int sz=path.size()+1;
      sz/=2;
      printf("%d\n",path[sz]);
      for(int i=1;i<=n;i++)
        edge[i].clear(),dist[i].clear();
      path.clear();
      vis.clear();
    }
    return 0;
}
