#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

bool vis[30][105];
string yes="YES";
string no="NO";
int n,m;
queue<int> x,y;
vector<string> v;

void clean(){
	while(x.size())
		x.pop();
	while(y.size())
		y.pop();
	v.clear();
	memset(vis,false,sizeof vis);
	return ;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<3;i++){
			string temp;
			cin>>temp;
			for(int j=0;j<n;j++)
				if(temp[j]=='s')
					x.push(i),y.push(j);
			v.push_back(temp);
		}

		while(x.size()){
			int j=x.front(); int i=y.front();
			x.pop(),y.pop();
			if(i<n and j-1>=0 and v[j-1][i+3]=='.' and v[j-1][i+1]=='.' and v[j-1][i+2]=='.' and !vis[j-1][i+3])
				vis[j-1][i+3]=true,y.push(i+3),x.push(j-1);
			if(i<n and j+1<3 and v[j+1][i+3]=='.' and v[j+1][i+1]=='.' and v[j+1][i+2]=='.' and !vis[j+1][i+3])
				vis[j+1][i+3]=true,y.push(i+3),x.push(j+1);
			if(i<n and v[j][i+3]=='.' and v[j][i+1]=='.' and v[j][i+2]=='.' and !vis[j][i+3])
				vis[j][i+3]=true,y.push(i+3),x.push(j);			
		}
		if(vis[0][n-1] or vis[1][n-1] or vis[2][n-1])
			cout<<yes<<"\n";
		else
			cout<<no<<"\n";

		clean();
	}
	return 0;
}