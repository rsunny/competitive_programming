#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int l, r, a;
	cin >> l >> r >> a;
	int res = min(l, r);
	int ab = abs(l - r);
	if (a <= ab)
		res = 2 * (res + a);
	else
		res = ((l + r + a) / 2 ) * 2;
	cout << res << "\n";
	return 0;
}
