#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <string.h>
#include <limits>
#include <bitset>

using namespace std;

int r, c;
long long int b;
vector<long long int> m, s ,p;
long long int maxres = 2e18;
long long int dp[25][6][6];

long long int doit(int lb, int pos, int ch) {
	if(!lb) 
		return maxres;
	
	if(pos == c or ch >= r)
		return -2;
	
	if(dp[lb][pos][ch] != -1)
		return dp[lb][pos][ch];

	long long int res = 0;
	
	for (int i = 0; i <= min((long long int)lb, m[pos]); ++i) {
		long long int ans = (s[pos] * i) + (p[pos] * (i != 0));
		long long int temp = doit(lb - i, pos + 1, ch + (i != 0));
		res = max(res, min(temp, ans));
	}
	dp[lb][pos][ch] = res;
	return res;
}

void solve() {
	cin >> r >> b >> c;
	for (int i = 0; i < c; ++i) {
		long long int tm, ts, tp;
		m.push_back(tm);
		s.push_back(ts);
		p.push_back(tp);
	}
	memset(dp, -1, sizeof dp);
	cout << doit(b, 0, 0) << "\n";
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
