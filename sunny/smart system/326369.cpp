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

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
vector<pair<ll, ll> > p;
vector<pair<ll, ll> > s;
vector<pair<ll, ll> > tmp;

ll dp[1100][1100];

long min_time(vector < int > m_arrive, vector < int > m_req, vector < int > e_arrive, vector < int > e_req) {
    int n=m_arrive.size();
    int m=e_req.size();
    assert(n>0 and n<=1000);
    assert(m>0 and m<=1000);
    assert((int)m_arrive.size()==n and (int)m_req.size()==n);
    for (int i = 0; i < n; ++i) {
        ll a, b;
        a = m_arrive[i];
        b = m_req[i];
        assert(a>0 and a<=100000);
        assert(b>0 and b<=100000);
        p.push_back(make_pair(a, b));
    }
    sort(p.begin(), p.end());
    assert((int)e_arrive.size()==m and (int)e_req.size()==m);
    for (int i = 0; i < m; ++i) {
        ll a, b;
        a = e_arrive[i];
        b = e_req[i];
        assert(a>0 and a<=100000);
        assert(b>0 and b<=100000);
        tmp.push_back(make_pair(a, b));
    }
    sort(tmp.begin(), tmp.end());
    int mx = 0;
    reverse(tmp.begin(), tmp.end());
    for (int i = 0; i < m; ++i) {
        if (tmp[i].second > mx) {
            mx = tmp[i].second;
            s.push_back(tmp[i]);
        }
    }
    reverse(s.begin(), s.end());
    m = s.size();
    for (int i = 0; i <= n; ++i) {
        if (i == 0)
            dp[i][0] = 0;
        else
            dp[i][0] = max(dp[i - 1][0], p[i - 1].first) + p[i - 1].second;
        ll go = INF;
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = INF;
            if (i > 0)
                dp[i][j] = min(dp[i][j], max(dp[i - 1][j], p[i - 1].first) + p[i - 1].second);
            dp[i][j] = min(dp[i][j], max(dp[i][j - 1], s[j - 1].first) + s[j - 1].second);
            dp[i][j] = min(dp[i][j], max(go, s[j - 1].first + s[j - 1].second));
            go = min(max(go, s[j - 1].first + s[j - 1].second), max(dp[i][j - 1], s[j - 1].first) + s[j - 1].second);
        }
    }
    return dp[n][m];
}

int main() {
    long res;
    
    int _m_arrive_size = 0;
    cin >> _m_arrive_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _m_arrive;
    int _m_arrive_item;
    for(int _m_arrive_i=0; _m_arrive_i<_m_arrive_size; _m_arrive_i++) {
        cin >> _m_arrive_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _m_arrive.push_back(_m_arrive_item);
    }
    
    
    int _m_req_size = 0;
    cin >> _m_req_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _m_req;
    int _m_req_item;
    for(int _m_req_i=0; _m_req_i<_m_req_size; _m_req_i++) {
        cin >> _m_req_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _m_req.push_back(_m_req_item);
    }
    
    
    int _e_arrive_size = 0;
    cin >> _e_arrive_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _e_arrive;
    int _e_arrive_item;
    for(int _e_arrive_i=0; _e_arrive_i<_e_arrive_size; _e_arrive_i++) {
        cin >> _e_arrive_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _e_arrive.push_back(_e_arrive_item);
    }
    
    
    int _e_req_size = 0;
    cin >> _e_req_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _e_req;
    int _e_req_item;
    for(int _e_req_i=0; _e_req_i<_e_req_size; _e_req_i++) {
        cin >> _e_req_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _e_req.push_back(_e_req_item);
    }
    
    res = min_time(_m_arrive, _m_req, _e_arrive, _e_req);
    cout << res;
    
    return 0;
}

