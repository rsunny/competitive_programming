#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <utility>

using namespace std;

#define mp make_pair

priority_queue< pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > heap;
long double eps = 1e-9;
int n, l;
int mid;

bool check(int num) {
	if (num % n == 0)
		return true;
	return (num % n < mid);
}

void solve() {
	while (heap.size())
		heap.pop();
	cin >> n >> l;
	int num;
	mid = (n + 1) / 2;
	int sum = 0;
	int tot = 0;
	int sum_rest = 0;
	for (int i = 0; i < l; ++i) {
		cin >> num;
		tot += num;
		num *= 100;
		int mod = num % n;
		cout << num << " " << check(num) << "\n";
		if (check(num)) {
			cout << mid - mod << " " << num << "\n";
			heap.push(mp(mid - mod, num));
		}
		else
			sum_rest += (num / n) + 1;
		sum += (num / n) + !check(num);
	}
	int lft = n - tot;
	if (!check(100)) {
		int val = lft * ((100 / n) + !check(100));
		cout << sum + val << "\n";
		return ;
	}
	sum = sum_rest;
	cout << sum << "\n";
	while (heap.size()) {
		pair<int,int> tp = heap.top();
		heap.pop();
		cout << tp.first << " " << tp.second << "\n";
		if(tp.first <= lft)	{
			lft -= tp.first;
			tp.second += tp.first;
		}
		cout << tp.first << " " << tp.second << "\n";
		sum += (tp.second / n) + 1;
	}
	int val = lft * ((100 / n) + !check(100));
	sum += val;
	cout << sum << "\n";
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
