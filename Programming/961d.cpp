#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <unordered_map>

using namespace std;

typedef long long int LL;

int n, a;
LL ans;
unordered_map<int, LL> v[200009];

inline int lowbit(int x) {
    return x&(-x);
}

void add(int x, int y, LL val) {
    for (int i = x; i <= 200001; i += lowbit(i))
    	for (int j = y; j <= 200001; j += lowbit(j)){
        	v[i][j] += val;
    	}
}

LL get(int x, int y) {
    LL res = 0;
    for (int i = x; i; i -= lowbit(i))
	    for (int j = y; j; j -= lowbit(j))
        	res += v[i][j];
    return res;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a;
		a = min(a, n);
		add(i, 1, (LL)1);
		for (int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				cout<<get(j,k)<<" ";
			}
			cout<<"\n";
		}
			cout<<"\n";
		add(i + 1, 1, (LL)-1);
		for (int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				cout<<get(j,k)<<" ";
			}
			cout<<"\n";
		}
			cout<<"\n";
		add(i, a + 1, (LL)-1);
		for (int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				cout<<get(j,k)<<" ";
			}
			cout<<"\n";
		}
			cout<<"\n";
		add(i + 1, a + 1, (LL)1);
		for (int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				cout<<get(j,k)<<" ";
			}
			cout<<"\n";
		}
			cout<<"\n";
		ans += get(i, a - 1) - get(i - 1, a - 1) ;
	}

	// for (int i = 1; i <= n; ++i) {
	// 	cin >> a;
	// 	a = min(a, n);
	// 	ans += max(a - i, 0);
	// }
	
	cout << ans << "\n";
	return 0;
}
