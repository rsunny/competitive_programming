#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> e[100009];
vector<int> tm[100009];
int n;

int t;

void dfs(int v){
	t++;
	sort(e[v].begin(), e[v].end());
	tm[v].push_back(t);
	int temp=t;
	do{
		t=temp;
		for(int i=0;i<(int)e[v].size();i++)
			dfs(e[v][i]);
	}while(next_permutation(e[v].begin(), e[v].end()));
	return ;
}

int main(){	
	cin>>n;
	int p;
	for(int i=2;i<=n;i++){
		cin>>p;
		e[p].push_back(i);
	}
	dfs(1);
	for(int i=1;i<=n;i++){
		cout<<i<<" : ";
		int sum=0;
		sort(tm[i].begin(), tm[i].end());
		for(int j=0;j<(int)tm[i].size();j++){
			cout<<tm[i][j]<<" ";
			sum+=tm[i][j];
		}
		cout<<" = "<<sum<<"\n";
	}
	return 0;
}
