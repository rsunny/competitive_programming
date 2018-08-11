#include <bits/stdc++.h>

using namespace std;


const int Nmax = 5e5 + 5;
const int logNmax = 25;

int depth[Nmax], pos[Nmax], euler[2 * Nmax], rmq[logNmax][2 * Nmax], l[2 *Nmax], euler_count;
vector<int> v[Nmax];

void dfs(int x, int p) {
    euler[++euler_count] = x;
    pos[x] = euler_count;
    if (p) {
        depth[x] = depth[p] + 1;
    }
    for (auto &it: v[x]) {
        if (it != p) {
            dfs(it, x);
            euler[++euler_count] = x;
        }
    }
}

int lca(int x, int y) {
    if (pos[x] > pos[y]) {
        swap(x, y);
    }
    int dif = pos[y] - pos[x] + 1;
    int log_dif = l[dif];

    int best = rmq[log_dif][pos[x]];
    if (depth[rmq[log_dif][pos[x] + dif - (1 << log_dif)]] < depth[best]) {
        best = rmq[log_dif][pos[x] + dif - (1 << log_dif)];
    }

    return best;
}

int dist(int x, int y) {
    return depth[x] + depth[y] - 2 * depth[lca(x, y)];
}

void initLCA() {
    dfs(1, 0);

    for (int i = 2; i <= euler_count; ++i) {
        l[i] = l[i / 2] + 1;
    }

    for (int i = 1; i <= euler_count; ++i) {
        rmq[0][i] = euler[i];
    }

    for (int j = 1; (1 << j) <= euler_count; ++j) {
        for (int i = 1; i <= euler_count; ++i) {
            rmq[j][i] = rmq[j - 1][i];
            if (i + (1 << (j - 1)) <= euler_count) {
                if (depth[rmq[j - 1][i + (1 << (j - 1))]] < depth[rmq[j][i]]) {
                    rmq[j][i] = rmq[j - 1][i + (1 << (j - 1))];
                }
            }
        }
    }
}

/*
 * Complete the function below.
 */
int findD(int n, vector <int> edge1, vector <int> edge2, int a, int b, int c) {

    assert(n>0 and n<=500000);
    assert(a!=b and b!=c and a!=c);
    
    for (int i = 0; i < n-1; ++i) {
        int x, y;
        x=edge1[i];
        y=edge2[i];
        assert(x>0 and x<=n and y>0 and y<=n);
        assert(x!=y);
        v[x].push_back(y);
        v[y].push_back(x);
    }

    initLCA();

    for(int i=n;i>=0;i--){
        int A=dist(i,a);
        int B=dist(i,b);
        int C=dist(i,c);
        if(A==B and B==C)
            return i;
    }
    assert(false);
    return 0;
}

int main() {

    int res;
    int n;
    cin >> n;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int edge1_size = 0;
    cin >> edge1_size;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    vector<int> edge1;
    for(int i = 0; i < edge1_size; i++) {
        int edge1_item;
        cin >> edge1_item;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        edge1.push_back(edge1_item);
    }

    int edge2_size = 0;
    cin >> edge2_size;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    vector<int> edge2;
    for(int i = 0; i < edge2_size; i++) {
        int edge2_item;
        cin >> edge2_item;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        edge2.push_back(edge2_item);
    }

    int a;
    cin >> a;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int b;
    cin >> b;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int c;
    cin >> c;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    res = findD(n, edge1, edge2, a, b, c);
    cout << res << endl;

    return 0;
}

