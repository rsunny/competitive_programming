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

const int N=500;
int a[N];
map<int,int> le;
map<int,int> ri;
pair<int,int> pos[N];
int v[N];

int lowbit(int x) {
    return x & -x;
}

int get(int x) {
    int ret=0;
    while (x) {
        ret+=v[x];
        x-=lowbit(x);
    }
    return ret;
}
 
void add(int x,int add) {
    while (x<N) {
        v[x]+=add;
        x+=lowbit(x);
    }
}

int move_them(int n, vector < int > arr) {
    assert(n>0 and n<=200);
    n*=2;
    memset(v,0, sizeof(v));
    le.clear();
    ri.clear();
    for (int i=1;i<=n;i++) {
        a[i]=arr[i-1];
        assert(a[i]>=1 and a[i]<=1000);
        if (le[a[i]]==0)
            le[a[i]]=i;
        else ri[a[i]]=i;
    }
    assert(le.size()==ri.size() and (int)le.size()==n/2);
    int cnt=1;
    for (map<int,int>::iterator it=le.begin();it!=le.end();it++) {
        int key=it->first;
        int val1=it->second;
        int val2=ri[key];
        pos[cnt].first=val1;
        pos[cnt++].second=val2;
    }
    sort(pos+1,pos+cnt);
    int tot=n/2;
    long long ret=(tot-1)*1LL*tot/2LL;
    for (int i=tot;i>=1;i--) {
        int r=pos[i].second;
        ret+=get(r);
        add(r,1);
    }
    memset(v,0,sizeof v);
    for (int i=1;i<=tot;i++) {
        int l=pos[i].first;
        int r=pos[i].second;
        ret-=get(l);
        add(r,1);
    }
    return ret;
}

int main() {
    int res;
    int _n;
    cin >> _n;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    
    int _arr_size = 0;
    cin >> _arr_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _arr;
    int _arr_item;
    for(int _arr_i=0; _arr_i<_arr_size; _arr_i++) {
        cin >> _arr_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _arr.push_back(_arr_item);
    }
    
    res = move_them(_n, _arr);
    cout << res << endl;
    
    return 0;
}
