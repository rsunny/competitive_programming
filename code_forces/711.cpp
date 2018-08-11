#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

struct edge{int e, nxt;};

const int MAXE=200005;
const int MAXV=200005;

int V, E;
edge e[MAXE], er[MAXE];
int sp[MAXV], spr[MAXV];
int group_cnt, group_num[MAXV];
bool v[MAXV];
int stk[MAXV];
long long int pow2[200005];
long long int mod=1e9+7;
int arr[200005];
int grp[200005];

void fill_forward(int x){
  int i;
  v[x]=true;
  for(i=sp[x];i;i=e[i].nxt) if(!v[e[i].e]) fill_forward(e[i].e);
  stk[++stk[0]]=x;
}

void fill_backward(int x){
  int i;
  v[x]=false;
  group_num[x]=group_cnt;
  for(i=spr[x];i;i=er[i].nxt) if(v[er[i].e]) fill_backward(er[i].e);
}

void add_edge(int v1, int v2){
  e [++E].e=v2; e [E].nxt=sp [v1]; sp [v1]=E;
  er[  E].e=v1; er[E].nxt=spr[v2]; spr[v2]=E;
}

void SCC(){
  int i;
  stk[0]=0;
  memset(v, false, sizeof(v));
  for(i=1;i<=V;i++) if(!v[i]) fill_forward(i);
  group_cnt=0;
  for(i=stk[0];i>=1;i--) if(v[stk[i]]){group_cnt++; fill_backward(stk[i]);}
}


int main(){
	pow2[0]=1;
	int n;
	cin>>n;
	V=n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		add_edge(i,arr[i]);
	}
	for(int i=1;i<200005;i++){
		pow2[i]=pow2[i-1]*2LL;
		pow2[i]%=mod;
	}
	SCC();
	long long int ans=1LL;
	for(int i=1;i<=n;i++){
		grp[group_num[i]]++;
	}
	for(int i=1;i<=group_cnt;i++){
		if(grp[i]==1)
			ans*=2LL;
		else{
			ans*=(pow2[grp[i]]-2LL);
		}
		ans%=mod;
	}
	cout<<ans<<"\n";
	return 0;
}
