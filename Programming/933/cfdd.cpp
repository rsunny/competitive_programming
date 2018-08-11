/* Heroes Never Die. */
#include <iostream>

using namespace std;
typedef long long LL;

template <class T> inline void read(T &_a) {
	bool _f = 0; int _c = 0; _a = 0;
	while (_c < '0' || _c > '9') _f |= _c == '-', _c = getchar();
	while (_c >= '0' && _c <= '9') _a = _a * 10 + _c - '0', _c = getchar();
	if (_f) _a = -_a;
}

#define MOD 1000000007

inline LL power(LL x, LL y) {
	LL ret = 1;
	for (x %= MOD; y; y >>= 1) {
		if (y & 1) ret = ret * x % MOD;
		x = x * x % MOD;
	}
	return ret;
}

#define inv(x) (power(x, MOD - 2))

#define MAXN 100005

int n, m;
int a[MAXN], b[MAXN];
LL f[MAXN], ans = 0;

int main() {
	read(n); read(m);
	
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) read(b[i]);

	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] && b[i]) {
			if (a[i] < b[i]) break;
			else if (a[i] > b[i]) {ans += f[i - 1]; break;}
			else f[i] = f[i - 1];
		}
		else if (!a[i] && !b[i]) {
			f[i] = (f[i - 1] * inv(m)) % MOD;
			ans += f[i - 1] * (m - 1) % MOD * inv(2 * m) % MOD;
		}
		else if (!a[i]) {
			f[i] = (f[i - 1] * inv(m)) % MOD;
			ans += f[i - 1] * (m - b[i]) % MOD * inv(m) % MOD; 
		}
		else {
			f[i] = (f[i - 1] * inv(m)) % MOD;
			ans += f[i - 1] * (a[i] - 1) % MOD * inv(m) % MOD; 
		}
		ans %= MOD;
	}
	cout << ans % MOD << endl;

	return 0;
}