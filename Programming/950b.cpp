#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;

long long int sum1[100009];
long long int sum2[100009];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m, ele;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> ele;
		sum1[i] = sum1[i - 1] + ele;
	}
	for (int i = 1; i <= m; ++i) {
		cin >> ele;
		sum2[i] = sum2[i - 1] + ele;
	}
	int res = 0;
	for (int j = 1, i = 1; j <= m and i <=n ; ) {
		if (sum1[i] == sum2[j]){
			++res;
			++i;
			++j;
		}
		else if (sum1[i] < sum2[j]) {
			++i;
		}
		else if (sum1[i] > sum2[j]) {
			++j;
		}
	}
	cout << res << "\n";
	return 0;
}
