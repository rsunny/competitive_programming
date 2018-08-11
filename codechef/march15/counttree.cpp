#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string.h>
#include <utility>
using namespace std;

int n,x,y,w,q,a,z;
vector<int>tree[1009];
pair<int,int> edges[1009];
bool vis[1009];
unordered_map<int,unordered_map<int,int> >c;
int par,res;

void dfs(int i,int gcd){
	vis[i]=1;
	if(gcd==1)
		res++;
	for(int j=0;j<tree[i].size();j++){
		if(!vis[tree[i][j]])
			dfs(tree[i][j],__gcd(gcd,c[i][tree[i][j]]));
	}
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<n;i++){
    	scanf("%d %d %d",&x,&y,&w);
    	tree[x].push_back(y);
    	tree[y].push_back(x);
    	c[x][y]=w;
    	c[y][x]=w;
    	edges[i]=make_pair(x,y);
    }
    res=0;
    for(int i=1;i<=n;i++){
		par=i;
		memset(vis,0,sizeof vis);
		vis[i]=1;
		for(int j=0;j<tree[i].size();j++){
			dfs(tree[i][j],c[i][tree[i][j]]);
		}
	}
	printf("%d\n",res/2);
    scanf("%d",&q);
    while(q--){
    	res=0;
    	scanf("%d %d",&a,&z);
    	c[edges[a].second][edges[a].first]=c[edges[a].first][edges[a].second]=z;
    	for(int i=1;i<=n;i++){
    		par=i;
    		memset(vis,0,sizeof vis);
    		vis[i]=1;
    		for(int j=0;j<tree[i].size();j++){
    			dfs(tree[i][j],c[i][tree[i][j]]);
    		}
    	}
    	printf("%d\n",res/2);
    }
    return 0;
}
