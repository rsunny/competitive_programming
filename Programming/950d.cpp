#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;

long long int n, len;

long long int get_element(long long int pos) {
	return (pos + 1LL) / 2LL;
}

long long int get_jump(long long int pos) {
	long long int ele = get_element(pos);
	long long int jmp = (2LL * (n - ele)) + 1LL;
	return (jmp >= pos) ? 0 : jmp;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int q;
	cin >> n;
	cin >> q;
	len = 2LL * n;

	while (q--) {
		long long int pos;
		cin >> pos;
		
		if (pos % 2LL) {
			cout << get_element(pos) << "\n";
			continue;
		}

		long long int l = 1;
		long long int r = n % 2LL ? n - 2LL : n - 1LL;

		while (l < r) {
			cout << l << " " << r << "\n";
			long long int mid = l + r;
			mid /= 2LL;
			if (mid % 2LL)
				mid--;
			long long int temp = mid;

			while (pos + mid <= len) {
				pos += mid;
				mid *= 2LL;
			}
			temp = pos;
			long long int jmp = get_jump(pos);

			while ()

			if (temp == jmp) {
				cout << get_element(pos) << "\n";
				break;
			}
			else if (temp < jmp)
				l = temp + 2LL;
			else if (temp > jmp)
				r = temp - 2LL;
		}
	}
	return 0;
}
