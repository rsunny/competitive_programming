#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;

string res = "abcdefghijklmnopqrstuvwxyz";

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	string s;
	int ans = 0;

	cin >> s;

	for (int i = 0; i < (int)s.size(); ++i) {
		if (s[i] <= ('a' + ans)) {
			s[i] = (char)('a' + ans);
			ans++;
		}
		if (ans == 26) {
			cout << s << "\n";
			return 0;
		}
	}

	cout << -1 << "\n";
	return 0;
}
