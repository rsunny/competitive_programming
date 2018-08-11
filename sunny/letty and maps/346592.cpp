#include <bits/stdc++.h>

using namespace std;

int mat[1009][1009];
bool vis[1009][1009];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n;

void DFS(int x,int y){
	vis[x][y]=1;
	for(int i=0;i<4;i++){
		int X=x+dx[i];
		int Y=y+dy[i];
		if(X>=0 and X<n and Y>=0 and Y<n and !vis[X][Y] and mat[X][Y]){
			DFS(X,Y);
		}
	}
	return ;
}

/*
 * Complete the function below.
 */
int findGroup(vector < string > mp) {
	n = mp.size();
	assert(n>0 and n<=1000);
	assert(n==(int)mp.size());
	
	for(int i=0;i<n;i++){
		assert((int)mp.size()==n);
		for(int j=0;j<n;j++){
			assert(mp[i][j]=='.' or mp[i][j]=='#');
			mat[i][j]=(mp[i][j]=='.'?1:0);
		}
	}
	
	int res=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(mat[i][j] and !vis[i][j]){
				res++;
				DFS(i,j);
			}
		}
	}
	return res;
}

int main() {
    int res;
    
    int _mp_size = 0;
    cin >> _mp_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<string> _mp;
    string _mp_item;
    for(int _mp_i=0; _mp_i<_mp_size; _mp_i++) {
        getline(cin, _mp_item);
        _mp.push_back(_mp_item);
    }
    
    res = findGroup(_mp);
    cout << res << endl;
    
    return 0;
}
