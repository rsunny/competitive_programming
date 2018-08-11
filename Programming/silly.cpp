#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;

long double dp[1009];
long double eps = 1e-7;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	dp[0] = 300;
	for(int i = 0; i <= 1000; ++i) {
		long double st = (double)i/10;	
		int flag = 0;
		for(int j = i + 1; j <= 1000; ++j) {
			if (i == 200 and j == 530) {
				flag = 1;
			}
			long double tot = dp[i];
			long double ans = 0;
			long double ed = (double)j/10;
			while (tot + eps > 100 + eps) {
				tot -= 100;
				ans += (100 - (2 * (ed - st)));
				if (flag)
					cout << tot << " " << ans << "\n";
			}
			ans += tot - (ed - st);
			dp[j] = max(dp[j], ans + eps);
			if (flag)
				return 0;
		}
	}
	for (int i = 1; i <= 1000; ++i) {
		cout << (long double)i/10 << " " << dp[i] << "\n"; 
	}
	return 0;
}