#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;

int d;
string p;

void solve() {
	cin >> d >> p;
	int sp = 0;
	while(1) {
		int dmg = 0;
		int s = 1;
		int c = -1;
		for (int i = 0; i < (int)p.size(); ++i) {
			if (p[i] == 'S')
				dmg += s;
			else {
				s *= 2;
				if (i + 1 < (int)p.size() and p[i + 1] == 'S')
					c = i;
			}
		}
		if (dmg <= d)
			break;
		if(c == -1) {
			cout << "IMPOSSIBLE\n";
			return ;
		}
		swap(p[c], p[c + 1]);
		++sp;
	}
	cout << sp <<"\n";
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
