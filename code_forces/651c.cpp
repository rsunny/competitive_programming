#include <iostream>
#include <map>

using namespace std;

map<int,int> x,y;
map<pair<int,int> ,int> xy;

int main(){
	int n,xx,yy;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>xx>>yy;
		x[xx]++;
		y[yy]++;
		xy[make_pair(xx,yy)]++;
	}
	map<int,int> :: iterator it;
	long long int ans=0,temp;
	for(it=x.begin();it!=x.end();it++)
		temp=it->second,ans+=(temp*(temp-1))/2;
	for(it=y.begin();it!=y.end();it++)
		temp=it->second,ans+=(temp*(temp-1))/2;

	map<pair<int,int> ,int> :: iterator t;
	for(t=xy.begin();t!=xy.end();t++)
		temp=t->second,ans-=(temp*(temp-1))/2;
	cout<<ans<<"\n";
	return 0;
}