#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <string.h>
#include <ostream>

using namespace std;

int a, x, y;
bool mp[5][1009];
int dx[] = {0,-1,1,0,-1,1,0,-1,1};
int dy[] = {0,0,0,-1,-1,-1,1,1,1};
map<int, map<int, int> > pos;

void solve() {
	memset(mp, false, sizeof mp);
	cin >> a;
	int X = 2, Y = 2;
	int ans = 0;
	int flag = 0;
	while(1) {
		cout << X << " " << Y << "\n" << flush;
		cin >> x >> y;
		if (x <= 0 or y <= 0){
			cout << "out of bounds\n";
			return ;
		}
		mp[x][y] = true;
		flag |= (1 << pos[x - X][y - Y]);

		if (flag == (1 << 9) - 1) {
			ans += 9;
			Y += 3;
			flag = 0;
		}
		if (ans >= a)
			break;
	}
	return ;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int test, t = 1;
	cin >> test;

	pos[0][0] = 0;
	pos[-1][0] = 1;
	pos[1][0] = 2;
	pos[0][-1] = 3;
	pos[-1][-1] = 4;
	pos[1][-1] = 5;
	pos[0][1] = 6;
	pos[-1][1] = 7;
	pos[1][1] = 8;

	while(test--){
		solve();
		++t;
	}
	return 0;
}
