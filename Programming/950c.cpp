#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;

vector<int> zi, oi;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	if (s[0] == '1' or s[n - 1] == '1') {
		cout << "-1\n";
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') {
			zi.push_back(i + 1);
		}
		else {
			oi.push_back(i + 1);
		}
	}
	cout << zi.size() - 1 << "\n";
	for(int i = 0; i < zi.size() - 1; ++i) {
		if(i == 0) {
			cout << oi.size() + 2 << " ";
			cout << zi[0] << " ";
			for (int j = 0; j < oi.size(); ++j)
				cout << oi[j] << " ";
			cout << zi[(int)zi.size() - 1] << "\n";
		}
		else {
			cout << 1 << " " << zi[i] << "\n";
		}
	}
	return 0;
}
