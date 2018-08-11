#include <iostream>
#include <vector>

using namespace std;

vector<int> edge[1005];
vector<int> people;
int vis[1005],res[1005];
int k,n,m;

void dfs(int node){
	vis[node]=1;
	for(int i=0;i<(int)edge[node].size();i++)
		if(!vis[edge[node][i]])
			dfs(edge[node][i]);
	return ;
}

int main(){
	int t,a,b;
	int test=1,cnt;
	cin>>t;
	while(t--){
		cnt=0;
		cout<<"Case "<<test++<<": ";
		people.clear();
		for(int i=0;i<1005;i++)
			edge[i].clear(),res[i]=0;
		cin>>k>>n>>m;
		for(int i=0;i<k;i++){
			cin>>a;
			people.push_back(a);
		}
		for(int i=0;i<m;i++){
			cin>>a>>b;
			edge[a].push_back(b);
		}
		for(int i=0;i<k;i++){
			dfs(people[i]);
			for(int j=1;j<=n;j++)
				res[j]+=vis[j],vis[j]=0;
		}
		for(int i=1;i<=n;i++)
			cnt+=(res[i]==k);
		cout<<cnt<<"\n";
	}
	return 0;
}