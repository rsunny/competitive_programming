#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <map>
#include <unordered_map>
#include <cassert>
#include <sys/resource.h>

using namespace std;

#define MAXN 200009

int n,m;
int c[MAXN];
unordered_map<int,unordered_map<int,bool> > dup;
map<int,long long int> clr[MAXN];
map<int,long long int> tot_clr[MAXN];
map<int,long long int> sqr[MAXN];
map<int,long long int> sum[MAXN];
vector<int> graph[MAXN];
int dfsNum[MAXN];
int num;
int artPoint[MAXN];
int artblock[MAXN];
int visited[MAXN];
int number[MAXN];
vector<int> block[MAXN];
int w[MAXN];
int comp[MAXN];
long long int ans[MAXN];

int dfs(int pos,int prev){
	visited[pos]=1;
	int least_ancestor=dfsNum[pos]=num++;
	for(int i=0;i<graph[pos].size();i++){
		if(graph[pos][i]==pos)
			continue;
		if(dfsNum[graph[pos][i]]==0){
			int rec = dfs(graph[pos][i],pos);
			if(dfsNum[pos]==1 and dfsNum[graph[pos][i]]>2) artPoint[pos]=1;
			if(dfsNum[pos]!=1 and rec>=dfsNum[pos]) artPoint[pos]=1;
			least_ancestor = min(least_ancestor,rec);
		}else{
			least_ancestor = min(least_ancestor,dfsNum[graph[pos][i]]);
		}
	}
	return least_ancestor;
}

void make_group(int node){
	visited[node]=1;
	number[node]=num;
	for(int i=0;i<(int)graph[node].size();i++){
		int next_node=graph[node][i];
		if(!visited[next_node] and !artPoint[next_node])
			make_group(next_node);
	}
	return ;
}

void make_comp(int node,int root){
	comp[node]=root;
	map<int,long long int> :: iterator it;
	for(it=clr[node].begin();it!=clr[node].end();it++)
		tot_clr[root][(*it).first]+=(*it).second;
	for(int i=0;i<(int)block[node].size();i++){
		int next_node=block[node][i];
		if(!comp[next_node])
			make_comp(next_node,root);
	}
	return ;
}

void run_merge(int a,int b,int art){
	int pos=a;
	bool swp=false;
	if (clr[w[a]].size()<clr[w[b]].size()){
		swap(w[a],w[b]);
		swp=true;
	}
	int id=w[a];
	map<int,long long int>::iterator it;
	int val,amount;
	long long int temp;
	for (it=clr[w[b]].begin();it!=clr[w[b]].end();it++){
		val=(*it).first;
		amount=(*it).second;
		if(art){
			temp=(swp)?clr[w[a]][val]:clr[w[b]][val];
			sum[pos][val]+=temp;
			sqr[pos][val]+=(temp*temp);
		}
		clr[id][val]+=amount;
	}
	return ;
}

void traverse(int node){
	visited[node]=1;
	for(int i=0;i<(int)block[node].size();i++){
		int next_node=block[node][i];
		if(!visited[next_node]){
			traverse(next_node);
			run_merge(node,next_node,artblock[node]);
		}
	}
	if(artblock[node]){
		map<int,long long int> :: iterator it;
		long long int temp_sum=0;
		long long int temp_sqr=0;
		long long int temp;
		int root=comp[node];
		int val;
		for(it=sum[node].begin();it!=sum[node].end();it++){
			val=(*it).first;
			temp=tot_clr[root][val]-clr[w[node]][val];
			assert(temp>=0);
			temp_sum=sum[node][val]+temp;
			temp_sqr=sqr[node][val]+(temp*temp);
			temp=(temp_sum*temp_sum);temp-=temp_sqr;
			temp/=2LL;
			assert(temp>=0);
			ans[node]+=temp;
		}
	}
	return ;
}

int main(){
	const rlim_t kStackSize = 64 * 1024 * 1024;
    struct rlimit rl;
    rl.rlim_cur = kStackSize;
    setrlimit(RLIMIT_STACK, &rl);
    

	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		if(!dup[a][b]){
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		dup[a][b]=dup[b][a]=true;
	}
	for(int i=1;i<=n;i++)
		if(!visited[i])
			num=0,dfs(i,-1);
	for(int i=1;i<=n;i++)
		visited[i]=0;
	num=1;
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			if(!artPoint[i])
				make_group(i);
			else{
				number[i]=num;
				artblock[num]=1;
			}
			num++;
		}
	}
	for(int i=1;i<=n;i++){
		visited[i]=0;
		w[i]=i;
		clr[number[i]][c[i]]++;
	}
	map<int,long long int> block_edge[MAXN];
	for(int i=1;i<=n;i++){
		for(int j=0;j<(int)graph[i].size();j++)
			if(number[i]!=number[graph[i][j]]){
				block_edge[number[i]][number[graph[i][j]]]=1;
			}
	}
	map<int,long long int> :: iterator it;
	for(int i=1;i<num;i++){
		for(it=block_edge[i].begin();it!=block_edge[i].end();it++){
			int next_node=(*it).first;
			block[i].push_back(next_node);
		}
	}
	int val;
	long long int temp;
	for(int i=1;i<num;i++){
		if(!comp[i]){
			make_comp(i,i);
		}
	}
	for(int i=1;i<num;i++){
		if(!visited[i]){
			traverse(i);
			for(it=clr[w[i]].begin();it!=clr[w[i]].end();it++){
				val=(*it).first;
				temp=(*it).second;
				sum[0][val]+=temp;
				sqr[0][val]+=(temp*temp);
			}
		}
	}
	long long int answer=0;
	for(it=sum[0].begin();it!=sum[0].end();it++){
		val=(*it).first;
		temp=(sum[0][val]*sum[0][val]);
		temp-=sqr[0][val];
		temp/=2LL;
		assert(temp>=0);
		answer+=temp;
	}
	for(int i=1;i<=n;i++){
		val=number[i];
		val=comp[val];
		temp=tot_clr[val][c[i]]-1;
		if(artPoint[i]){
			val=number[i];
			temp+=ans[val];
		}
		answer+=temp;
		printf("%lld\n",answer);
		answer-=temp;
	}
	return 0;
}