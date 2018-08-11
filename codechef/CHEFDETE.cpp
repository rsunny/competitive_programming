#include <iostream>

using namespace std;

bool vis[100009];

int main(){
	int n,d;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>d,vis[d]=true;
	for(int i=1;i<=n;i++)
		if(!vis[i])
			cout<<i<<" ";
	cout<<"\n";
	return 0;
}