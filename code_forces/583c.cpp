#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int ele,n;
vector<int> v;

int main(){
	cin>>n;
	for(int i=1;i<=n*n;i++){
		cin>>ele;
		v.push_back(ele);
	}
	sort(v.begin(), v.end());
	for(int i=0;i<(int)v.size()-1;i++)
		cout<<v[i]<<" "<<__gcd(v[i],4)<<"\n";
	return 0;
}