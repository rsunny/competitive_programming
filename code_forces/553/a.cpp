#include <bits/stdc++.h>
using namespace std;

int n, m, n1;

const int N = 100100;
int par[N], rnk[N], col[N], seen[N];
vector<pair<int, int> > hate, love;
vector<int> G[N];
map<int, int> idx;

int find(int x)  {
 return (x == par[x]) ? x : par[x] = find(par[x]);
}

void merge(int _x, int _y)  {
 int x = find(_x), y = find(_y);
 if(x == y)  {
  return;
 }
 if(rnk[y] > rnk[x]) {
  swap(x, y);
 }
 par[y] = x;
 rnk[x] += rnk[y];
}

long long expMod(long long base, long long ex, long long mod)  {
  if(ex == 0) return 1;
  long long temp = expMod(base,ex/2,mod);
  temp = (temp*temp)%mod;
  if(ex%2) temp = (temp*base)%mod;
  return temp;
}

void dfs(int node, int color)  {
  if(seen[node])  {
    return;
  }
  seen[node] = 1;
  col[node] = color;
  for(int v: G[node]) {
    if(not seen[v]) {
      dfs(v, 1 - color);
    }
  }
}

int main()  {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for(int i=0; i<N; i++)  {
    par[i] = i;
    rnk[i] = 1;
  }
  for(int i=0; i<m; i++)  {
    int u, v, type;
    cin >> u >> v >> type;
    --u; --v;
    if(type == 1) {
      love.push_back({u, v});
      merge(u, v);
    } else  {
      hate.push_back({u, v});
    }
  }
  for(auto el: hate)  {
    if(find(el.first) == find(el.second)) {
      cout << "0\n";
      return 0;
    }
  }
  set<int> diff;
  for(int i=0; i<n; i++)  {
    diff.insert(find(i));
  }
  n1 = diff.size();
  for(int i=0, ptr=0; i<n; i++) {
    if(idx.find(find(i)) == idx.end())  {
      idx[find(i)] = ptr++;
    }
  }
  for(auto e: hate) {
    int u1 = e.first, v1 = e.second;
    int u = idx[find(u1)], v = idx[find(v1)];
    G[u].push_back(v);
    G[v].push_back(u);
  }
  for(int i=0; i<n1; i++) {
    dfs(i, 0);
  }
  for(auto e: hate)  {
    int u1 = e.first, v1 = e.second;
    int u = idx[find(u1)], v = idx[find(v1)];
    if(col[u] == col[v])  {
      cout << "0\n";
      return 0;
    }
  }
  for(int i=0; i<N; i++)  {
    par[i] = i;
    rnk[i] = 1;
  }
  for(int i=0; i<n1; i++) {
    for(int j: G[i])  {
      merge(i, j);
    }
  }
  set<int> diff2;
  for(int i=0; i<n1; i++) {
    diff2.insert(find(i));
  }
  cout << expMod(2, diff2.size() - 1, 1000000007) << "\n";
}