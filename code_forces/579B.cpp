#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<pair<int,pair<int,int> > >v;
int arr[1000];

int main(){
	int n,a,b,st;
	cin>>n;
	pair<int,int> team;
	for(int i=2;i<=2*n;i++){
		for(int j=1;j<i;j++){
			cin>>st;
			team=make_pair(i,j);
			v.push_back(make_pair(st,team));
		}
	}
	sort(v.rbegin(), v.rend());
	for(int i=0;i<v.size();i++){
		team=v[i].second;
		a=team.first;
		b=team.second;
		if(arr[a] or arr[b])
			continue;
		arr[a]=b;
		arr[b]=a;
	}
	for(int i=1;i<=2*n;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
	return 0;
}