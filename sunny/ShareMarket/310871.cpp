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

int h1,a1,d1;
int h2,a2,d2;
int xh,xa,xd;

int solve(int a1,int d1,int a2,int d2,int h2){
    if (a1<=d2) return -1;
    int w=(h2+(a1-d2)-1)/(a1-d2);
    return w*max(0,a2-d1);
}

int buyProp(int m1, int e1, int s1, int m2, int e2, int s2, int bm, int be, int bs) {
    h1 = m1, a1 = e1, d1 = s1;
    h2 = m2, a2 = e2, d2 = s2;
    xh = bm, xa = be, xd = bs;
    int ret=1000000000;
    for (int ca=0;ca<=200;ca++)
        for (int cd=0;cd<=101;cd++){
            int t=solve(a1+ca,d1+cd,a2,d2,h2);
            if (t<0) continue;
            int ch=max(0,t-h1+1);
            ret= min(ret,ca*xa+cd*xd+ch*xh);
        }
    return ret;
}

int main() {
    int res;
    int _m1;
    cin >> _m1;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    int _e1;
    cin >> _e1;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    int _s1;
    cin >> _s1;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    int _m2;
    cin >> _m2;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    int _e2;
    cin >> _e2;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    int _s2;
    cin >> _s2;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    int _bm;
    cin >> _bm;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    int _be;
    cin >> _be;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    int _bs;
    cin >> _bs;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    res = buyProp(_m1, _e1, _s1, _m2, _e2, _s2, _bm, _be, _bs);
    cout << res << endl;
    
    return 0;
}
