#include <iostream>
#include <string.h>
#include <memory.h>
#include <vector>
#include <stdio.h>
#include <stack>

using namespace std;

#define MAXV 20100

bool indegree[MAXV];
bool outdegree[MAXV];
vector<int> edge[MAXV], redge[MAXV];
int n,m,a,b;
int group_cnt, group_num[MAXV];
bool v[MAXV];
stack<int> stk;

void fill_forward(int x){
  v[x]=true;
  for(int i=0;i<(int)edge[x].size();i++)  if(!v[edge[x][i]])  fill_forward(edge[x][i]);
  stk.push(x);
  return ;
}

void fill_backward(int x){
  v[x]=true;
  group_num[x]=group_cnt;
  for(int i=0;i<(int)redge[x].size();i++)  if(!v[redge[x][i]])  fill_backward(redge[x][i]);
  return ;
}

void SCC(){
  group_cnt=0;
  for(int i=1;i<=n;i++) v[i]=false;

  for(int i=1;i<=n;i++) if(!v[i]) fill_forward(i);
  
  for(int i=1;i<=n;i++) v[i]=false;
  
  while(stk.size()){
    int ele=stk.top();
    stk.pop();
    if(!v[ele])
      group_cnt++, fill_backward(ele); 
  }
  return;
}

int main(){
  int t,test=0;
  scanf("%d",&t);
  while(t--){
    for(int i=1;i<=n;i++)
      indegree[i]=0, outdegree[i]=0, edge[i].clear(), redge[i].clear();

    test++;
    
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
      scanf("%d %d",&a,&b), edge[a].push_back(b), redge[b].push_back(a);

    SCC();
    
    for(int i=1;i<=n;i++){
      for(int j=0;j<(int)edge[i].size();j++){
        a=group_num[i], b=group_num[edge[i][j]];
        if(a==b)
          continue;
        indegree[b]=true;
        outdegree[a]=true;
      }
    }
    
    int icnt=0, ocnt=0;
    if(group_cnt>1)
      for(int i=1;i<=group_cnt;i++){
        if(!indegree[i])
          icnt++;
        if(!outdegree[i])
          ocnt++;
      }
    
    printf("Case %d: ",test);
    printf("%d\n",max(icnt,ocnt));    
  }
  return 0;
}