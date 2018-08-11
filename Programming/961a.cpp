#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;

int n, m, col;
int arr[1009];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m ; ++i) {
		cin >> col;
		arr[col]++;
	}
	int res = arr[1];
	for (int i = 2; i <= n; ++i) {
		res = min(res, arr[i]);
	}
	cout << res << "\n";
	return 0;
}
