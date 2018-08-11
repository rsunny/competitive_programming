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

bool check(int ca,int cd,int ch){
    int th1=h1+ch;
    int th2=h2;
    int ta1=a1+ca;
    int ta2=a2;
    int td1=d1+cd;
    int td2=d2;
    if(td2>=ta1)
        return false;
    while(th1>0 and th2>0){
        th1-=max(0,(ta2-td1));
        th2-=max(0,(ta1-td2));
        if(th1>0 and th2<=0)
            return true;
    }
    return false;
}

int buyProp(int m1, int e1, int s1, int m2, int e2, int s2, int bm, int be, int bs) {
    h1 = m1, a1 = e1, d1 = s1;
    h2 = m2, a2 = e2, d2 = s2;
    xh = bm, xa = be, xd = bs;
    int ret=1000000000;
    for (int ca=0;ca<=201;ca++)
        for (int cd=0;cd<=201;cd++){
            for(int ch=0;ch<=1001;ch++){
                if(check(ca,cd,ch) and ret>ca*xa+cd*xd+ch*xh){
                    ret=ca*xa+cd*xd+ch*xh;
                }
            }
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
