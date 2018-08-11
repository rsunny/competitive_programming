#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <string.h>

using namespace std;

int mat[505][505];
int pre[505][505];
int dp[505][505];
int tot[505];
vector< pair<int, int> > comp[505];
int n, m, K;
int maxi = 1e9;

int doit(int pos, int left) {
	if (left < 0)
		return 1e9;

	if (pos == n + 1) 
		return 0;

	if (dp[pos][left] != -1)
		return dp[pos][left];

	int res = maxi;

	for (int i = (int)comp[pos].size() - 1; i >= 0; --i) {
		int per = comp[pos][i].first;
		int dur = comp[pos][i].second;
		res = min(res, doit(pos + 1, left - tot[pos] + per) + dur);
	}

	dp[pos][left] = res;
	return res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> K;
	int ele;
	string s;
	memset(dp, -1, sizeof dp);

	for (int i = 1; i <= n; ++i) {
		cin >> s;
		int sum = 0;
		int temp;
		for (int j = 1; j <= m; ++j) {
			ele = s[j - 1] - '0';
			sum += ele;
			mat[i][j] = sum;
			pre[i][j] = 1000;
		}

		tot[i] = sum;
		pre[i][0] = 0;
		for (int j = 1; j <= m; ++j) {
			for (int k = j; k <= m; ++k) {
				temp = mat[i][k] - mat[i][j - 1];
				pre[i][temp] = min(pre[i][temp], k - j + 1);
			}
		}

		for (int j = 0; j <= m; ++j) {
			if (pre[i][j] != 1000) {
				comp[i].push_back({j, pre[i][j]});
			}
		}
	}

	int res = doit(1, K);
	if (res == maxi)
		res = -1;
	cout << res << "\n";

	return 0;
}
