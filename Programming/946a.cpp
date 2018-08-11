#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin>>n;
	int res = 0;
	for(int i=0;i<n;i++){
		int ele;
		cin>>ele;
		res+=abs(ele);
	}
	cout<<res<<"\n";
	return 0;
}
