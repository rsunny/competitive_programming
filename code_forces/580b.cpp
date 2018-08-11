#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int,int> >v;
vector<int> m;
long long int s[100005];


int main(){
	int n,d,a,b;
	cin>>n>>d;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		v.push_back(make_pair(a,b));
	}
	sort(v.begin(), v.end());
	for(int i=0;i<n;i++){
		m.push_back(v[i].first);
		s[i+1]=s[i]+(long long int)v[i].second;
	}
	vector<int> :: iterator low;
	long long int maxi=-1;
	for(int i=0;i<n;i++){
		a=m[i]+d-1;
		low=upper_bound(m.begin(), m.end(), a);
		maxi=max(maxi,s[low-m.begin()]-s[i]);
	}
	cout<<maxi<<"\n";
	return 0;
}