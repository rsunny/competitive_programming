#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> tree[100005];
int n,m,x,y;
int cats[100005];
bool vis[100005];

int dfs(int id,int cons){

	vis[id]=true;
	int cnt=0;
	int some=0;

	if(cons==m+1)
		return 0;

	for(int i=0;i<(int)tree[id].size();i++){
		if(!vis[tree[id][i]])
			some++;
	}
	if(some==0)
		return 1;

	for(int i=0;i<(int)tree[id].size();i++){
		int ct=0;
		if(cats[tree[id][i]])
			ct=cons+cats[tree[id][i]];
		if(!vis[tree[id][i]])
			cnt+=dfs(tree[id][i],ct);
	}
	return cnt;
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>cats[i];
	}
	for(int i=0;i<n-1;i++){
		cin>>x>>y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	cout<<dfs(1,cats[1])<<"\n";
	return 0;
}