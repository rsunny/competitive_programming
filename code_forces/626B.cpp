#include <iostream>
#include <queue>

using namespace std;

int n;
string s;
bool vis[209][209][209];

void bfs(int r, int g, int b){
	queue<int> R,G,B;
	R.push(r); G.push(g); B.push(b);
	vis[r][g][b]=true;
	while(R.size()){
		r=R.front(); g=G.front(); b=B.front();
		R.pop(), G.pop(), B.pop();
		if(r>1 and !vis[r-1][g][b])
			R.push(r-1),G.push(g),B.push(b), vis[r-1][g][b]=true;
		if(g>1 and !vis[r][g-1][b])
			R.push(r),G.push(g-1),B.push(b), vis[r][g-1][b]=true;
		if(b>1 and !vis[r][g][b-1])
			R.push(r),G.push(g),B.push(b-1), vis[r][g][b-1]=true;
		if(r>0 and g>0 and !vis[r-1][g-1][b+1])
			R.push(r-1),G.push(g-1),B.push(b+1), vis[r-1][g-1][b+1]=true;
		if(r>0 and b>0 and !vis[r-1][g+1][b-1])
			R.push(r-1),G.push(g+1),B.push(b-1), vis[r-1][g+1][b-1]=true;
		if(b>0 and g>0 and !vis[r+1][g-1][b-1])
			R.push(r+1),G.push(g-1),B.push(b-1), vis[r+1][g-1][b-1]=true;
	}
}

int main(){
	cin>>n;
	cin>>s;
	int r=0,g=0,b=0;
	for(int i=0;i<n;i++){
		if(s[i]=='R')
			r++;
		else if(s[i]=='G')
			g++;
		else b++;
	}
	bfs(r,g,b);
	if(vis[0][0][1])
		cout<<"B";
	if(vis[0][1][0])
		cout<<"G";
	if(vis[1][0][0])
		cout<<"R";
	cout<<"\n";
	return 0;
}