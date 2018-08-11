#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;

int cum[100009];
int act[100009];
int thr[100009];
int n, k;
int awk;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> thr[i];
		cum[i] = cum[i-1] + thr[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> awk;
		act[i] = act[i-1] + (awk * thr[i]);
	}
	int res = 0;
	for (int i = 1; i <= n - k + 1; ++i) {
		int a = i;
		int b = i + k - 1;
		res = max(res, act[a - 1] + cum[b] - cum[a-1] + act[n] - act[b]);
	}
	cout << res << "\n";
	return 0;
}
