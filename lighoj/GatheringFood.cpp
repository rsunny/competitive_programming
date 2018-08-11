#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int mat[20][20];
int vis[20][20];
int xpos[30];
int ypos[30];
int n;

int bfs(int st){
	int ed=st+1;
	queue<int> x,y,s;
	memset(vis,0,sizeof vis);
	x.push(xpos[st]); y.push(ypos[st]), s.push(0);
	while(x.size()){
		int posx = x.front(); 
		int posy = y.front();
		int stp = s.front();
		x.pop(), y.pop(), s.pop();
		if(posx==xpos[ed] and posy==ypos[ed])
			return stp;
		for(int i=0;i<4;i++){
			if(posx+dx[i]>=0 and posx+dx[i]<n and posy+dy[i]>=0 and posy+dy[i]<n and !vis[posx+dx[i]][posy+dy[i]])
				if(mat[posx+dx[i]][posy+dy[i]]!=-1 and mat[posx+dx[i]][posy+dy[i]]<=ed)
					vis[posx+dx[i]][posy+dy[i]]=true, x.push(posx+dx[i]), y.push(posy+dy[i]), s.push(stp+1);
		}
	}
	return -1;
}

int main(){
	int t,test=1;
	cin>>t;
	while(t--){
		int cnt=0;
		cin>>n;
		cout<<"Case "<<test++<<": ";
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			for(int j=0;j<n;j++){
				if(s[j]=='.')
					mat[i][j]=0;
				else if(s[j]=='#')
					mat[i][j]=-1;
				else{
					mat[i][j]=s[j]-'A';
					mat[i][j]++;
					cnt++;
					xpos[mat[i][j]]=i;
					ypos[mat[i][j]]=j;
				}
			}
		}

		int res=0;
		int flag=1;
		for(int i=1;i<cnt;i++){
			int ret = bfs(i);
			if(ret==-1){
				cout<<"Impossible\n";
				flag=0;
				break;
			}
			res+=ret;
			mat[xpos[i]][ypos[i]]=0;
		}
		if(flag)
			cout<<res<<"\n";

	}
	return 0;
}