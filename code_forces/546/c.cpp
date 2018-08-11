#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <cstdio>

using namespace std;

vector<int> a,b;
map<vector<int>,map<vector<int>,bool> > state;

int main(){
	int n,c;
	cin>>n;
	int na,nb;
	cin>>na;
	for(int i=0;i<na;i++){
		cin>>c;
		a.push_back(c);
	}
	cin>>nb;
	for(int i=0;i<nb;i++){
		cin>>c;
		b.push_back(c);
	}
	int step=0;
	while(1){
		if(state[a][b] or state[b][a]){
			cout<<"-1\n";
			return 0;
		}
		state[a][b]=state[b][a]=true;
		if(a.size()==0 or b.size()==0)
			break;
		step++;
		int ac=a[0],bc=b[0];
		a.erase(a.begin());
		b.erase(b.begin());
		if(ac>bc){			
			a.push_back(bc);
			a.push_back(ac);
		}
		if(bc>ac){			
			b.push_back(ac);
			b.push_back(bc);
		}
	}
	int win=1;
	if(b.size()){
		win=2;
	}
	cout<<step<<" "<<win<<"\n";
	return 0;
}