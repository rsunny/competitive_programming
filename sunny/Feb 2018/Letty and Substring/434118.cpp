#include <iostream>
#include <vector>
#include <stdio.h>
#include <cassert>
#include <algorithm>

using namespace std;

vector<int> dp[27];
int cum[1000009];

int findMax(vector<int> points, string strg) {
    strg = " " + strg;
    int n = strg.size();
    assert(n > 1 and n <= 1000001);
    assert((int)points.size() == 26);
    int res = -1e9;
    for(int i=1;i<n;i++){
        assert(strg[i] >= 'a' and strg[i] <= 'z');
        int ind = strg[i] - 'a';
        cum[i] = (cum[i-1] + points[ind]);
        dp[ind].push_back(i);
        res=max(res,points[ind]);
    }
    for(int i=0;i<26;i++){
        int ans = points[i];
        assert(ans >= -10 and ans <= 10);
        for(int j=1;j<dp[i].size();j++){
            ans += cum[dp[i][j]] - cum[dp[i][j-1]];
            ans = max(ans,points[i]);
            res=max(res,ans);
        }
    }
    return res;
}

int main(){
    int points_count;
    cin >> points_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> points(points_count);

    for (int points_itr = 0; points_itr < points_count; points_itr++) {
        int points_item;
        cin >> points_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        points[points_itr] = points_item;
    }

    string strg;
    getline(cin, strg);

    int res = findMax(points, strg);

    cout << res << "\n";

    return 0;
}
