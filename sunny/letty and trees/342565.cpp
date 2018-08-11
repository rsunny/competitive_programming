#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int inf = (int) 1e9;
const int mod = (int) 1e9 + 7;
const int N = (int) 1e5 + 5;

int t[N], n;

inline void A (int p, int d) {
        while (p <= n) {
                t[p] += d;
                p += p & (-p);
        }
}

inline int G (int p) {
        int s = 0;
        while (p) {
                s += t[p];
                p -= p & (-p);
        }
        return s;
}

vector< pair<int, int> > a[N];
vector<int> g[N];
int m, ans, tin[N], tout[N], timer, p[N][20];

inline void Dfs (int v, int pr) {
        tin[v] = ++timer;
        p[v][0] = pr;
        for (int i = 1; i < 20; i++) {
                p[v][i] = p[p[v][i - 1]][i - 1];
        }
        for (auto to : g[v]) {
                if (tin[to] == 0) {
                        Dfs (to, v);
                }
        }
        tout[v] = ++timer;
}

inline bool Upper (int u, int v) {
        return tin[u] <= tin[v] && tout[v] <= tout[u];
}

inline int LCA (int u, int v) {
        if (Upper (u, v)) {
                return u;
        }
        if (Upper (v, u)) {
                return v;
        }
        for (int i = 19; i >= 0; i--) {
                if (!Upper (p[u][i], v)) {
                        u = p[u][i];
                }
        }
        return p[u][0];
}

inline void Calc (int v) {
        tin[v] = ++timer;
        for (auto to : g[v]) {
                if (tin[to] > tin[v]) {
                        Calc (to);
                }
        }
        tout[v] = timer;
        for (auto i : a[v]) {
                int f = G (tin[i.first]) - G (tin[v]);
                int s = G (tin[i.second]) - G (tin[v]);
                if (f + s == 0) {
                        ans++;
                        A (tin[v], 1);
                        A (tout[v] + 1, -1);
                        return;
                }
        }
}

/*
 * Complete the function below.
 */

int findSubset(int nn, vector < int > edge1, vector < int > edge2, vector < int > st, vector < int > ed) {
    n = nn;
    m = st.size();
    
    assert(n>=1 and n<=10000);
    assert(m>=1 and m<=10000);

    assert(edge1.size()==edge2.size() and (int)edge1.size()==n-1);
    assert(st.size()==ed.size());

    for (int i = 1; i < n; i++) {
            int x, y;
            x = edge1[i-1];
            y = edge2[i-1];

            assert(x>=1 and x<=n);
            assert(y>=1 and y<=n);
            assert(x!=y);

            g[x].emplace_back (y);
            g[y].emplace_back (x);
    }
    
    Dfs (1, 1);
    timer = 0;

    for (int i = 1; i <= m; i++) {
            int x, y;
            x = st[i-1];
            y = ed[i-1];
            
            assert(x>=1 and x<=n);
            assert(y>=1 and y<=n);

            a[LCA (x, y)].emplace_back (make_pair (x, y));
    }
    Calc (1);
    return ans;
}

int main() {
    int res;
    int _n;
    cin >> _n;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    
    int _edge1_size = 0;
    cin >> _edge1_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _edge1;
    int _edge1_item;
    for(int _edge1_i=0; _edge1_i<_edge1_size; _edge1_i++) {
        cin >> _edge1_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _edge1.push_back(_edge1_item);
    }
    
    
    int _edge2_size = 0;
    cin >> _edge2_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _edge2;
    int _edge2_item;
    for(int _edge2_i=0; _edge2_i<_edge2_size; _edge2_i++) {
        cin >> _edge2_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _edge2.push_back(_edge2_item);
    }
    
    
    int _st_size = 0;
    cin >> _st_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _st;
    int _st_item;
    for(int _st_i=0; _st_i<_st_size; _st_i++) {
        cin >> _st_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _st.push_back(_st_item);
    }
    
    
    int _ed_size = 0;
    cin >> _ed_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _ed;
    int _ed_item;
    for(int _ed_i=0; _ed_i<_ed_size; _ed_i++) {
        cin >> _ed_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _ed.push_back(_ed_item);
    }
    
    res = findSubset(_n, _edge1, _edge2, _st, _ed);
    cout << res << endl;

    return 0;
}
