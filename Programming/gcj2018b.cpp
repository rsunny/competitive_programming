#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;

int n;
vector<int> arr[2];
vector<int> V1, V2;

void solve() {
	arr[0].clear();
	arr[1].clear();
	V1.clear();
	V2.clear();

	cin >> n;
	int v;
	for (int i = 0; i < n; ++i) {
		cin >> v;
		arr[i % 2].push_back(v);
		V1.push_back(v);
	}
	sort(arr[0].begin(), arr[0].end());
	sort(arr[1].begin(), arr[1].end());
	sort(V1.begin(), V1.end());
	for (int i = 0; i < (int)max(arr[0].size(), arr[1].size()); ++i) {
		if (i < arr[0].size())
			V2.push_back(arr[0][i]);
		if (i < arr[1].size())
			V2.push_back(arr[1][i]);
	}
	for (int i = 0; i < n; ++i) {
		if (V1[i] != V2[i]) {
			cout << i << "\n";
			return;
		}
	}
	cout << "OK\n";
	return ;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int test, t = 1;
	cin >> test;
	while(test--){
		cout << "Case #" << t << ": ";
		solve();
		++t;
	}
	return 0;
}
