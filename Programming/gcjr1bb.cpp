#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <utility>

using namespace std;

vector<int> a, b;
int a_back[100005];
int b_back[100005];
int n;
map<int, int> mp;

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int d, A, B;
		cin >> d >> A >> B;
		a.push_back(d + A);
		b.push_back(d - B);
	}
	a_back[n - 1] = n - 1;
	b_back[n - 1] = n - 1;
	for (int i = n - 2; i >= 0; --i) {
		a_back[i] = i;
		if (a[i + 1] == a[i])
			a_back[i] = a_back[i + 1];
		b_back[i] = i;
		if (b[i + 1] == b)
			b_back[i] = b_back[i + 1];
	}
	for (int i = 0; i < n; ++i) {
		int res = a_back[i] - i + 1;
		int ptr = a_back[i] + 1;
		if (ptr < n)
			res += b_back[ptr] - ptr + 1;
		mp[res] += 1;
		res = b_back[i] - i + 1;
		ptr = b_back[i] + 1;
		if (ptr < n)
			res += a_back[ptr] - ptr + 1;
		mp[res] += 1;
	}
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
