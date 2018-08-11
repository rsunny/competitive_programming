#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

int n;
int v[100005];
vector<int> tz;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin>>n;

	int sum=0;
	v[0] = 0;

	for(int i=1;i<=n;i++){
		cin>>v[i];
		sum+=v[i];
		v[i]=sum;
	}

	int s,f;
	cin>>s>>f;

	int dist = f-s;
	int ans = 0;
	int res = 0;

	for(int i=1;i<=n;i++){
		int a = i;
		int b = a + dist - 1;
		if(b>n){
			ans = v[n] - v[a-1] + v[n-b];
		}
		else{
			ans = v[b] - v[a-1];
		}
		if(res<ans){
			res = ans;
			tz.clear();
			tz.push_back(i);
		}
		else if(res==ans)
			tz.push_back(i);
	}

	res=1e9;
	for(int i=0;i<tz.size();i++){
		int pos = tz[i];
		if(pos <= s)
			ans = s-pos+1;
		else
			ans = s + n - pos + 1;
		res=min(res,ans);
	}
	cout<<res<<"\n";
	return 0;
}
