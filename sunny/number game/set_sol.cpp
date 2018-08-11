#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

#include <assert.h>

/*
 * Complete the function below.
 */

long long dp[2][100];

string convert(long long int n){
    string s="";
    while(n){
        if(n%2LL)
            s="1"+s;
        else
            s="0"+s;
        n/=2LL;
    }
    return s;
}

long min_opr(long n) {
    string s;
    assert(n>0 and n<=1000000000000000);

    s=convert(n);
    n = (int) s.size ();
    reverse(s.begin(), s.end());

    if (s[0] == '0') {
        dp[0][0] = 0;
        dp[1][0] = 1;
    }
    else {
        dp[0][0] = 1;
        dp[1][0] = 0;
    }
    for (int i = 1; i < n; ++i) {
        if (s[i] == '0') {
            dp[0][i] = dp[0][i - 1];
            dp[1][i] = dp[1][i - 1] + (1ll << i);
        }
        else {
            dp[0][i] = dp[1][i - 1] + (1ll << i);
            dp[1][i] = dp[0][i - 1];
        }
    }
    return dp[0][n - 1];
}

int main() {
    long res;
    long _n;
    cin >> _n;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    res = min_opr(_n);
    cout << res;
    
    return 0;
}
