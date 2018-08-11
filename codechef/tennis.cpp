#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string.h>
#include <algorithm>

#define ll long long
#define sec second
#define fir first
#define pb push_back
#define mp make_pair

using namespace std;

int n;
vector<pair<int,int> >v[10005];
vector<int> tree[10005];
int visited[10005],maxi=0,main_value=0,dist[10005];

void dfs(int index){
	for(int i=0;i<v[index].size();i++){
		if(!visited[v[index][i].fir]){
			visited[v[index][i].fir]=1;
			dist[v[index][i].fir]=dist[index]+v[index][i].sec;
			if(dist[v[index][i].fir]>maxi){
				maxi=dist[v[index][i].fir];
				main_value=v[index][i].fir;
			}
			dfs(v[index][i].fir);
		}
	}
	return;
}


int bfs_node(int st){
	int max_level=0;
	queue<int> q,l;
	q.push(st);
	l.push(0);
	visited[st]=1;
	int ret=st;
	while(q.size()){
		int node = q.front();
		int level = l.front();
		q.pop(),l.pop();
		if(max_level<level)
			ret=node,max_level=level;
		for(int i=0;i<(int)tree[node].size();i++){
			if(!visited[tree[node][i]]){
				visited[tree[node][i]]=1;
				q.push(tree[node][i]);
				l.push(level+1);
			}
		}
	}
	return ret;
}

int bfs_level(int st){
	int max_level=0;
	queue<int> q,l;
	q.push(st);
	l.push(0);
	visited[st]=1;
	while(q.size()){
		int node = q.front();
		int level = l.front();
		q.pop(),l.pop();
		max_level = max(max_level,level);
		for(int i=0;i<(int)tree[node].size();i++){
			if(!visited[tree[node][i]]){
				visited[tree[node][i]]=1;
				q.push(tree[node][i]);
				l.push(level+1);
			}
		}
	}
	return max_level;
}

int main(){
	int test,x,y,z;
	scanf("%d",&test);
	while(test--){
		scanf("%d",&n);
		memset(dist,0,sizeof dist);
		memset(visited,0,sizeof visited);	
		int start;
		for(int i=0;i<10005;i++)
			v[i].clear(),tree[i].clear();
		for(int i=0;i<n-1;i++){
			scanf("%d%d",&x,&y);
			z=1;
			if(i==0)
				start=x;
			v[x].pb(mp(y,z));
			v[y].pb(mp(x,z));
			tree[x].pb(y);
			tree[y].pb(x);
		}
		if(n==2){
			printf("NO\n");
			continue;
		}
		main_value=0;
		visited[start]=1;
		dist[start]=0;
		maxi=-1;
		dfs(start);
		memset(visited,0,sizeof visited);
		memset(dist,0,sizeof dist);
		//cout<<main_value<<" FU \n";
		visited[main_value]=1;
		dist[main_value]=0;
		maxi=-1;
		int temp=main_value;
		dfs(main_value);
		tree[temp].pb(main_value);
		tree[main_value].pb(temp);
		memset(visited,0,sizeof visited);
		int node = bfs_node(start);
		memset(visited,0,sizeof visited);
		// for(int i=1;i<=n;i++){
		// 	if(dist[i]==maxi){
		// 		cout<<main_value<<" "<<i<<endl;
		// 		tree[main_value].pb(i);
		// 		tree[i].pb(main_value);
		// 		break;
		// 	}
		// }
		//cout<<"here\n";
		//cout<<maxi<<" "<<bfs()<<"\n";
		cout<<temp<<" "<<main_value<<"\n";
		int res = bfs_level(node);
		cout<<maxi<<" "<<res<<"\n";
		if(maxi==res)
			cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}