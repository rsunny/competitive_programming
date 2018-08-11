#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;

int n;
long long int m;
vector<long long int> s1, s2;
long long int dp[100005];
bool vis[100005];
long long int mod = 1e9 + 7;
long long int val;
long long int den;
long long int zero = 0LL;
long long int one = 1LL;

long long int power(long long int x, long long int y, long long int p){
    long long int res = one;
 
    x = x % p;
 
    while (y > zero){
       if (y % 2LL)
            res = (res*x) % p;
 
        y /= 2LL;
        x = (x*x) % p;  
    }

    return res;
}

long long int doit(int pos) {
	if(pos == n)
		return zero;
	
	if(vis[pos])
		return dp[pos];

	vis[pos] = true;
	long long int res = zero;

	if(s1[pos] and s2[pos]){
		if(s1[pos] != s2[pos])
			res = (s1[pos] > s2[pos]) ? one : zero;
		else res = doit(pos + 1);
	}
	else if(s1[pos] == zero and s2[pos] == zero){
		res = val;
		res += ((den * doit(pos + 1)) % mod);
		res %= mod;
	}
	else if(s1[pos] == zero){
		res = (m - s2[pos]) * den;
		res %= mod;
		res += ((den * doit(pos + 1)) % mod);
		res %= mod;
	}
	else if(s2[pos] == zero){
		res = (s1[pos] - 1LL) * den;
		res %= mod;
		res += ((den * doit(pos + 1)) % mod);
		res %= mod;
	}

	dp[pos] = res;
	return res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for(int i = 0; i < n; ++i){
		long long int temp;
		cin >> temp;
		s1.push_back(temp);
	}
	for(int i = 0; i < n; ++i){
		long long int temp;
		cin >> temp;
		s2.push_back(temp);
	}

	for(long long int i = 1LL; i < m; ++i){
		val += i;
	}
	
	den = power(m, mod - 2LL, mod);
	val *= den;
	val %= mod;
	val *= den;
	val %= mod;

	long long int ans = doit(0);
	cout << ans << "\n";
	return 0;
}
