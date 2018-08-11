#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin>>n;
	int res=0;
	for(int i=1;i<n;i++){
		res+=(n%i == 0);
	}
	cout<<res<<"\n";
	return 0;
}
