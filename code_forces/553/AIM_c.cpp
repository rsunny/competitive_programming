#include <iostream>
#include <vector>

using namespace std;

int n,m;
vector<int> edge[505];
int c[505][505];

int main(){
	cin>>n>>m;
	string s;
	for(int i=0;i<n;i++)
		s+="a";
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
		c[a][b]=c[b][a]=1;
	}
	int flag=1;
	for(int i=0;i<n;i++){
		c[i][i]=1;
		edge[i].push_back(i);
		if(edge[i].size()==n)
			s[i]='b';
		else if(flag){
			flag=0;
			for(int j=0;j<n;j++)
				if(!c[i][j])
					s[j]='c';
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if((max(s[i],s[j])-min(s[i],s[j])<=1 and !c[i][j]) or (max(s[i],s[j])-min(s[i],s[j])>1 and c[i][j])){
				cout<<"No\n";
				return 0;
			}
		}
	}
	cout<<"Yes\n"<<s<<"\n";
	return 0;
}