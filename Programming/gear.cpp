#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <math.h>

using namespace std;

#define MAXN 100009

int n, m;
int gear[MAXN];
int root[MAXN];
vector<int> edge[MAXN];
int sz[MAXN];
int parity[MAXN];
bool dirty[MAXN];
bool visited[MAXN];

void dfs(int node, int par, int x) {
    visited[node] = true;
    root[node] = x;
    parity[node] = par;
    for (int i = 0; i < (int)edge[node].size(); ++i) {
        if(!visited[edge[node][i]]) {
            dfs(edge[node][i], par ^ 1, x);
        }
    }
    visited[node] = false;
    return ;
}

void merge(int x, int y) {
    if (root[x] == root[y]) {
        dirty[root[x]] = true;
        return ;
    }
    dirty[root[x]] = dirty[root[y]] = dirty[root[x]] or dirty[root[y]];
    if (sz[root[x]] < sz[root[y]])
        swap(x, y);

    sz[root[x]] += sz[root[y]];
    sz[root[y]] = 0;
    dfs(y, parity[x] ^ 1, root[x]);
    return ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        cin >> gear[i];
        root[i] = i;
        sz[i] = 1;
    }
    
    int opt;
    int x, y, v;

    while(m--) {
        cin >> opt;
        if (opt == 1) {
            cin >> x >> v;
            gear[x] = v; 
        }
        else if (opt == 2) {
            cin >> x >> y;
            merge(x, y);
        }
        else {
            cin >> x >> y >> v;
            if (root[x] != root[y]) {
                cout << "0\n";
                continue;
            }
            if (dirty[root[x]]) {
                cout << "0\n";
                continue;
            }
            long long int neg = parity[x] == parity[y] ? 1LL : -1LL;
            long long int num = v * gear[x];
            long long int den = gear[y];
            long long int gcd = __gcd(num, den);
            cout << (neg * num) / gcd << "/" << den / gcd << "\n";
        }
    }
    return 0;
}
