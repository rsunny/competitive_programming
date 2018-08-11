#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	long long int n, m;
	cin >> n >> m;

	while(1) {
		if( n == 0 or m == 0) {
			break;
		}
		else if (n >= 2LL * m) {
			long long int i = n / (2LL * m);
			n -= (i * 2LL * m);
		}
		else if (m >= 2LL * n) {
			long long int i = m / (2LL * n);
			m -= (i * 2LL * n);
		}
		else {
			break;
		}
	}
	cout << n << " " << m << "\n";
	return 0;
}
