#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	int a, b;
	cin >> a;
	int diff = -1;
	for (int i = 1; i < n; ++i) {
		cin >> b;
		if (diff == -1 and abs(b - a) != 1)
			diff = abs(b - a);
		if (abs(b - a) != 1){
			if(diff != abs(b - a)) {
				cout << "NO\n";
				return 0;
			}
		}
		a = b;
	}
	cout << n << " " << diff << "\n";
	return 0;
}
