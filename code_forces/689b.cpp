#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <queue>

using namespace std;

const int maxn=200009;

vector<int> edge[maxn];
int res[maxn];
int vis[maxn];

int main(){
	int n,b,a;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&b);
		edge[i].push_back(b);
	}
	for(int i=1;i<=n;i++){
		if(i<n)
			edge[i].push_back(i+1);
		if(i>1)
			edge[i].push_back(i-1);
	}
	queue<int> q;
	q.push(1);
	vis[1]=1;
	while(q.size()){
		a=q.front();
		q.pop();
		for(int i=0;i<(int)edge[a].size();i++){
			b=edge[a][i];
			if(!vis[b]){
				vis[b]=1;
				res[b]=res[a]+1;
				q.push(b);
			}
		}
	} 
	for(int i=1;i<=n;i++)
		cout<<res[i]<<" ";
	cout<<"\n";
	return 0;
}