#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

map<long long int, int> freq;
map<int,int> rmp;
long long int strt;
int n,a;

void update(int i){
	while(i<=200000){
		freq[i] += 1;
		i+= i&-i;
	}
}

ll read(int i){
	ll sum=0;
	while(i>0){
		sum+=freq[i];
		i-= i&-i;
	}
	return sum;
}
vector<pair<pair<long long int, long long int> ,int> >Y1,Y2;

int main(){
	int n;
	long long int x1,x2,k,b,y1,y2;
	cin>>n;
	cin>>x1>>x2;
	for(int i=0;i<n;i++){
		cin>>k>>b;
		y1=(k*x1)+b;
		y2=(k*x2)+b;
		Y1.push_back(make_pair(make_pair(y1,y2),i));
		Y2.push_back(make_pair(make_pair(y2,y1),i));
	}
	sort(Y1.begin(), Y1.end());
	sort(Y2.begin(), Y2.end());

	for(int i=0;i<(int)Y1.size();i++){
		rmp[Y1[i].second]=i+1;
	}
	n=Y2.size();
	for(int i=0;i<n;i++){
		a=rmp[Y2[i].second];
		update(a);
		strt+=read(a);
	}
	ll ret=((ll)n*((ll)n+1));
	ret/=2;
	ret-=strt;
	if(ret>0)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}