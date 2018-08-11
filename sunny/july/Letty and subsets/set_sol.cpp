#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */
#define maxN 1009

int dp[maxN][maxN];

void add(int & a, int b) {
    a += b;
    a %= 2;
    return ;
}

int findXor(int n, int m) {
    int ans=0;
    
    dp[0][0] = 1;

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            add(dp[i + 1][j + 1], dp[i][j]);
            if (j + i <= n) add(dp[i][j + i], dp[i][j]);
        }
    }
    
    dp[0][0] = 1;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; i * j <= n && j <= m; j++) {
            if(dp[m - j][n - i * j])
                ans^=i;
        }
    }
    
    return ans;
    
}

int main(){

    int res;
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    res = findXor(n, m);
    cout << res << endl;

    return 0;
}
