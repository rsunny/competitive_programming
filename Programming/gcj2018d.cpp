#include <iostream>
#include <algorithm>
#include <math.h>
#include <iomanip>

using namespace std;

#define PI 3.14159265

void solve() {
	long double len;
	long double one = 1;
	cin >> len;
	len = one / len;
	long double a = acos(len) * 180.0 / PI;
	len = 0.5;
	cout << setprecision(9);
	long double cs = cos(a * PI / 180.0);
	long double sn = sin(a * PI / 180.0);
	long double tn = sn / cs;
	long double x = len * cs;
	long double y = x * tn; 
	// cout << tn << "\n";
	cout << x << " " << y << " " << 0 << "\n";
	cout << -1 * y << " " << x << " " << 0 << "\n";
	cout << 0 << " " << 0 << " " << 0.5 << "\n";
	return ;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int test, t = 1;
	cin >> test;
	while(test--){
		cout << "Case #" << t << ":\n";
		solve();
		++t;
	}
	return 0;
}
