#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <stdio.h>

#define fir first
#define sec second
#define ll long long
#define INF (int)1e9
#define pb push_back
#define mp make_pair
using namespace std;

struct compare{  
  bool operator()(const pair<int,pair<int,int> >& l, const pair<int,pair<int,int> >& r){
    if(l.fir==r.fir){
      return l.sec.fir > r.sec.fir;
    }
      return l.fir > r.fir;
    }
 };
 
vector<pair<int,int> >v[100010];
pair<int,int> dist[100010];  

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m,x,y,z;
  int src,dest,flag=0;
  cin>>n>>m;
  cin>>src>>dest;
  for(int i=0;i<m;i++){
    //cin>>x>>y>>z;
    scanf("%d %d %d",&x,&y,&z);
    v[x].pb(mp(y,z));
    v[y].pb(mp(x,z));
  }
  for(int i=0;i<n+1;i++){
    dist[i].fir=dist[i].sec=INF;
  }
  priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,compare>p;
  p.push(mp(0,mp(0,src)));
  while(!p.empty()){
    x=p.top().fir,y=p.top().sec.fir,z=p.top().sec.sec;
    p.pop();
    //cout<<x<<" "<<y<<" "<<z<<endl;
    if(x>dist[z].fir)
      continue;
    if(z==dest){
      flag=1;
      cout<<x-1<<" "<<y<<endl;
      break;
    }
    for(int i=0;i<v[z].size();i++){
      if(x+1<dist[v[z][i].fir].fir){
        dist[v[z][i].fir].fir=x+1;
        dist[v[z][i].fir].sec=y+v[z][i].sec;
        p.push(mp(x+1,mp(y+v[z][i].sec,v[z][i].fir)));
      }
      else if(x+1==dist[v[z][i].fir].fir){
        if(y+v[z][i].sec<dist[v[z][i].fir].sec){
          dist[v[z][i].fir].sec=y+v[z][i].sec;
          p.push(mp(x+1,mp(y+v[z][i].sec,v[z][i].fir)));
        }
      }
    }
  }
  if(flag==0){
    cout<<"-1 -1\n";
  }
  return 0;
}