#include <iostream>
#include <string.h>

using namespace std;

int m,n;
char fnd;
char maze[55][55];
bool vis[55][55];
bool v[55][55];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void dfs(int x,int y){
	vis[x][y]=;
	for(int i=0;i<4;i++){
		int xx=x+dx[i];int yy=y+dy[i];
		if(xx>=0 and xx<n+2 and yy>=0 and yy<m+2 and !vis[xx][yy] and fnd!=maze[xx][yy])
			dfs(xx,yy);
	}
}

int main(){
	int t,test=1;
	cin>>t;
	while(t--){
		cout<<"Case "<<test++<<":";
		cin>>n>>m;
		memset(maze,'.',sizeof maze);
		memset(vis,false,sizeof vis);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>maze[i][j]
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(!vis[i][j] and maze[i][j]!='.'){
					fnd=maze[i][j];
					memset(v,false,sizeof v);
					dfs(0,0);
				}
	}
	return 0;
}