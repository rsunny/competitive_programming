#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string.h>
#include <unordered_map>
using namespace std;

vector<int> idx[100010],mp[100010];
unordered_map<int,unordered_map<int,bool> > vis;
bool pre[100010];
int a[100010];
int res[100010];
int maxele;

int main(int argc, char const *argv[]){
	int n,k,ele;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&ele);
		pre[ele]=true;
		idx[ele].push_back(i);
		a[i]=ele;
		maxele=max(maxele,ele);
	}
	for(int i=1;i<=n;i++){
		int y=a[i];
		for(int j=0;(y*j)+k<=maxele;j++){
			int x=(y*j)+k;
			if(x%y==k and pre[x] and pre[y] and !vis[x][y])
				vis[x][y]=true, mp[x].push_back(y);
		}
	}
	for(int i=1;i<=n;i++){
		int x=a[i];
		int pos=n+1;
		for(int j=0;j<(int)mp[x].size();j++){
			int y=mp[x][j];
			int found = upper_bound(idx[y].begin(), idx[y].end(), i) - idx[y].begin();
			if(found!=idx[y].size())
				pos=min(pos,idx[y][found]);
		}
		res[i]=pos;
	}
	long long int ret=0;
	int frst=n+1;
	for(int i=n;i>=1;i--){
		frst=min(frst,res[i]);
		ret+=(frst-i);
	}
	cout<<ret<<"\n";
	return 0;
}