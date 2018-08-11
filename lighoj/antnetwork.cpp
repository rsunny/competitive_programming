#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[10010];
int dfsNum[10010];
int num,n,m,a,b;
long long int res1,res2,sz;
int artPoint[10010];
bool vis[10010];

int dfs(int pos,int prev){
	int least_ancestor=dfsNum[pos]=num++;
	for(int i=0;i<graph[pos].size();i++){
		if(graph[pos][i]==pos)
			continue;
		if(dfsNum[graph[pos][i]]==0){
			int rec = dfs(graph[pos][i],pos);
			if(dfsNum[pos]==1 and dfsNum[graph[pos][i]]>2) artPoint[pos]=1;
			if(dfsNum[pos]!=1 and rec>=dfsNum[pos]) artPoint[pos]=1;
			least_ancestor = min(least_ancestor,rec);
		}
		else{
			least_ancestor = min(least_ancestor,dfsNum[graph[pos][i]]);
		}
	}
	return least_ancestor;
}

void count_comp(int a){
	sz++;
	vis[a]=true;
	for(int i=0;i<(int)graph[a].size();i++){	
		b=graph[a][i];
		if(!vis[b] and !artPoint[b])
			count_comp(b);
	}	
	return ;
}

void clear(){
	for(int i=0;i<n;i++){
		graph[i].clear();
		artPoint[i]=0;
		dfsNum[i]=0;
		vis[i]=0;
	}
	num=0; res1=0; res2=1;
	return ;
}

int main(){
	int t,test=0;
	cin>>t;
	while(t--){
		clear();
		test++; 
		cin>>n>>m;
		for(int i=0;i<m;i++)
			cin>>a>>b, graph[a].push_back(b), graph[b].push_back(a);
		dfs(0,-1);
		for(int i=0;i<n;i++){
			if(!vis[i] and !artPoint[i])
				res1++, sz=0, count_comp(i), res2*=sz;
		}		
		cout<<"Case "<<test<<": "<<res1<<" "<<res2<<"\n";
	}
	return 0;
}


