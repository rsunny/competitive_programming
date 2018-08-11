#include <iostream>
#include <map>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int mat[1009][1009];
bool vis[1009][1009];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n,res,sz;
map<int,int> sze;

void DFS(int x,int y){
	vis[x][y]=1;
	for(int i=0;i<4;i++){
		int X=x+dx[i];
		int Y=y+dy[i];
		if(X>=0 and X<n and Y>=0 and Y<n and !vis[X][Y] and mat[X][Y]){
			DFS(X,Y);
		}
	}
	sz++;
	return ;
}

vector < int > countGroups(vector < vector < int > > m, vector < int > t) {
	n=m.size();
	assert(n>0 and n<=1000);
	for(int i=0;i<n;i++){
		assert((int)m[i].size()==n);
		for(int j=0;j<n;j++){
			mat[i][j]=m[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(mat[i][j] and !vis[i][j]){
				sz=0;
				DFS(i,j);
				sze[sz]++;
			}
		}
	}
	vector<int> res;
	int tsz;
	tsz=t.size();
	assert(tsz>0 and tsz<=n);
	for(int i=0;i<tsz;i++){
		sz=t[i];
		assert(sz>=1 and sz<=(n*n));
		res.push_back(sze[sz]);
	}
	return res;
}

int main() {
    vector < int > res;
    
    int _m_rows = 0;
    int _m_cols = 0;
    cin >> _m_rows >> _m_cols;
    vector< vector < int > > _m(_m_rows);
    for(int _m_i=0; _m_i<_m_rows; _m_i++) {
        for(int _m_j=0; _m_j<_m_cols; _m_j++) {
            int _m_tmp;
            cin >> _m_tmp;
            _m[_m_i].push_back(_m_tmp);
        }
    }
    
    
    int _t_size = 0;
    cin >> _t_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _t;
    int _t_item;
    for(int _t_i=0; _t_i<_t_size; _t_i++) {
        cin >> _t_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _t.push_back(_t_item);
    }
    
    res = countGroups(_m, _t);
    for(int res_i=0; res_i < res.size(); res_i++) {
    	cout << res[res_i] << endl;;
    }
    
    return 0;
}
