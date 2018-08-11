#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;

long long int n;
long long int ans;
long long int cnt;
int ind;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	int k;
	cin>>k;
	for(int i=1;i<=k;i++){
		long long int type;
		long long int temp;
		cin>>type;
		temp = type;
		type = (n/type) * type;

		if(cnt<=type){
			cnt = type;
			ans = n/temp;
			ind = i;
		}
	}
	cout<<ind<<" "<<ans<<"\n";
	return 0;
}
