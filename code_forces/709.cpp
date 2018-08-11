#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

vector<int> v;
vector<int> l,m,r;

int main(){
	int n,a;
	cin>>n>>a;
	for(int i=0;i<n;i++){
		int ele;
		cin>>ele;
		v.push_back(ele);
	}
	sort(v.begin(), v.end());
	int l,r;
	int res=1e9;
	if(v.size()==1){
		cout<<0<<"\n";
		return 0;
	}
	l=v[1];
	r=v[n-1];
	if(l<=a and r<=a){
		res=min(res,abs(a-l));
	}
	else if(l>=a and r>=a){
		res=min(res,abs(a-r));
	}
	else{
		res=min(res,2*abs(a-l)+abs(a-r));
		res=min(res,2*abs(a-r)+abs(a-l));
	}

	l=v[0];
	r=v[n-2];
	if(l<=a and r<=a){
		res=min(res,abs(a-l));
	}
	else if(l>=a and r>=a){
		res=min(res,abs(a-r));
	}
	else{
		res=min(res,2*abs(a-l)+abs(a-r));
		res=min(res,2*abs(a-r)+abs(a-l));
	}
	cout<<res<<"\n";
	return 0;
}
