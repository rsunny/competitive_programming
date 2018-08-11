#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

vector<int> tree[10005],level[10005];
bool vis[10005];
int depth;
set<pair<int,int> >ed;

void dfs(int node,int l){
	level[l].push_back(node);
	vis[node]=true;
	if(node==10000)
		depth=l;
	for(int i=0;i<(int)tree[node].size();i++){
		if(!vis[tree[node][i]])
			dfs(tree[node][i],l+1);
	}
	// if((int)tree[node].size()==0)
	// 	ed.insert(make_pair(node,10000));
}

int main(){
	int n,m,a,b,e,s=1,t=10000;
	// n = 1000;
	// m = 0; 
	cin>>n>>m;
	//cin>>s>>t;
	// vector<int> one,two,three;
	// int i;
	// for(i=2;i<(n/3);i++)
	// 	one.push_back(i);
	// for(;i<(2*n/3);i++)
	// 	two.push_back(i);
	// for(;i<(n);i++)
	// 	three.push_back(i);
	// for(int i=0;i<one.size();i++){
	// 	for(int j=0;j<two.size();j++){
	// 		m++;
	// 	}
	// }
	// for(int i=0;i<three.size();i++){
	// 	for(int j=0;j<two.size();j++){
	// 		m++;
	// 	}
	// }
	//cout<<n<<" "<<m<<"\n";
	//cout<<1<<" "<<5000<<"\n";
	for(int i=1;i<=m;i++){
			cin>>a>>b>>e;
			//cin>>a>>b;
			ed.insert(make_pair(min(a,b),max(a,b)));
			tree[a].push_back(b);
			//cout<<a<<" "<<b<<" "<<e<<"\n";
	}
	dfs(1,0);
	for(int i=0;i<10000;i++){
		for(int k=0;k<(int)level[i].size();k++){
			if((int)ed.size()+1>500000)
				break;
			for(int j=0;j<(int)level[i+1].size();j+=3){
				if((int)ed.size()+1>500000)
					break;
				a=level[i][k],b=level[i+1][j];
				ed.insert(make_pair(min(a,b),max(a,b)));
			}
		}
	}
	//cout<<depth<<"\n";
	//return 0;
	cout<<n<<" "<<(int)ed.size()<<"\n";
	cout<<s<<" "<<t<<"\n";
	set<pair<int,int> > :: iterator it;
	for(it=ed.begin();it!=ed.end();it++){
		e =rand()%100;e++;
		cout<<(*it).first<<" "<<(*it).second<<" "<<e<<"\n";
	}
	// for(int i=0;i<one.size();i++){
	// 	for(int j=0;j<two.size();j++){
	// 	 	e=rand()%100;e++;
	// 		cout<<one[i]<<" "<<two[j]<<" "<<e<<"\n";
	// 	}
	// }
	// for(int i=0;i<three.size();i++){
	// 	for(int j=0;j<two.size();j++){
	// 	 	e=rand()%100;e++;
	// 		cout<<three[i]<<" "<<two[j]<<" "<<e<<"\n";
	// 	}
	// }
	return 0;
}