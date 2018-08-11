#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n;
set<int>s;
int temp;

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>temp;
		while(temp%2==0)
			temp/=2;
		while(temp%3==0)
			temp/=3;
		s.insert(temp);
	}
	if(s.size()==1)
		cout<<"Yes\n";
	else
		cout<<"No\n";
	return 0;
}