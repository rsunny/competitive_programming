#include <bits/stdc++.h>

using namespace std;

const int N = 110;
const int B = 15;
const long long mod = 1e5 + 7ll;

long long dp1[N][N][N][B];
long long dp2[N][N][N][B];


/*
 * Complete the function below.
 */
int calCount(int s, int n, int m) {
    int t,k;
    t=s;
    k=m;
    t /= 2;

    for (int dis = 0; dis <= t; ++dis) {
        for (int pos = 0; pos <= n+1; ++pos) {
            for (int used = 0; used <= n; ++used) {
                for (int bounce = 0; bounce < B; ++bounce) {
                    if (pos == 0) {
                        dp1[dis][pos][used][bounce] = (dis + used + bounce == 0);
                        dp2[dis][pos][used][bounce] = (dis + used + bounce == 0);
                    } else if (pos == n+1) {
                        dp1[dis][pos][used][bounce] = (
                            dp1[dis][pos-1][used][bounce] + 
                            (dis >= pos and bounce ? dp1[dis-pos][pos][used][bounce-1] : 0)
                        ) % mod;
                        dp2[dis][pos][used][bounce] = (
                            dp2[dis][pos-1][used][bounce] +
                            (dis >= pos and bounce ? dp1[dis-pos][pos][used][bounce-1] : 0)
                        ) % mod;
                    } else {
                        dp1[dis][pos][used][bounce] = (
                            dp1[dis][pos-1][used][bounce] +
                            (dis >= pos and used and bounce ? dp1[dis-pos][pos-1][used-1][bounce-1] : 0)
                        ) % mod;
                        dp2[dis][pos][used][bounce] = (
                            dp2[dis][pos-1][used][bounce] +
                            (dis >= pos and used and bounce ? dp1[dis-pos][pos-1][used-1][bounce-1] : 0) +
                            (used ? dp2[dis][pos-1][used-1][bounce] : 0)
                        ) % mod;
                    }
                }
            }
        }
    }

    long long ans = 0ll;
    for (int dis = 0; dis <= t; ++dis) {
        int left_dis = t - dis;
        for (int used = 0; used <= k and used <= n; ++used) {
            int left_used = k - used;
            for (int bounce = 0; bounce < B; ++bounce) {
                if (bounce > 0) 
                    ans = (ans + 
                        dp2[dis][n+1][used][bounce] *
                        dp2[left_dis][n+1][left_used][bounce-1]
                    ) % mod;
                ans = (ans + 
                    dp2[dis][n+1][used][bounce] *
                    dp2[left_dis][n+1][left_used][bounce]
                ) % mod;
            }
        }
    }


    return ans;
}

int main() {
    int res;
    int _s;
    cin >> _s;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    int _n;
    cin >> _n;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    int _m;
    cin >> _m;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    res = calCount(_s, _n, _m);
    cout << res << endl;
    
    return 0;
}
