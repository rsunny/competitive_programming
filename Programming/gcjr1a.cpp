#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;

int h, v;
int r, c;
vector<string> mp;
vector<int> hh;
vector<int> vv;

void solve() {
	mp.clear();
	hh.clear();
	vv.clear();

	int tc = 0;
	cin >> r >> c >> h >> v;
	string s;
	for(int i = 0; i < r; ++i) {
		cin >> s;
		mp.push_back(s);
		for(int j = 0; j < c; ++j) {
			if(mp[i][j] == '@')
				++tc;
		}
	}

	int th = h;
	int tv = v;
	int rh = tc / (h + 1);
	int rv = tc / (v + 1);
	int er = tc / ((h + 1) * (v + 1));
	if(rh * (h + 1) != tc or rv * (v + 1) != tc or tc != er * (h + 1) * (v + 1)) {
		cout << "IMPOSSIBLE\n";
		return ;
	}

	int i = 0;
	while(th--) {
		int cnt = 0;
		for( ; i < r; ++i) {
			for(int j = 0; j < c; ++j) {
				if(mp[i][j] == '@')
					++cnt;
			}
			if(cnt >= rh)
				break;
		}
		if(cnt > rh or cnt < rh) {
			cout << "IMPOSSIBLE\n";
			return ;
		}
		hh.push_back(i);
		++i;
	}
	hh.push_back(r - 1);

	int j = 0;
	while(tv--) {
		int cnt = 0;
		for( ; j < c; ++j) {
			for(int i = 0; i < r; ++i) {
				if(mp[i][j] == '@')
					++cnt;
			}
			if(cnt >= rv)
				break;
		}
		if(cnt > rv or cnt < rv) {
			cout << "IMPOSSIBLE\n";
			return ;
		}
		vv.push_back(j);
		++j;
	}
	vv.push_back(c - 1);

	int pr = 0;
	int pv = 0;
	for(int i = 0; i < hh.size(); ++i) {
		int cr = hh[i];	
		for (int j = 0; j < vv.size(); ++j) {
			int cv = vv[j];
			int cnt = 0;
			for(int k = pr; k <= cr; ++k) {
				for(int l = pv; l <= cv; ++l) {
					cnt += (mp[k][l] == '@');
				}
			}
			if (cnt != er) {
				cout << "IMPOSSIBLE\n";
				return ;
			}
			pv = cv + 1;
		}
		pr = cr + 1;
		pv = 0;
	}
	cout << "POSSIBLE\n";
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
