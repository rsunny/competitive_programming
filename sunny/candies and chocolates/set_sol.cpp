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
int toChocolate(int a, int b, int c, int d) {
    long long n=a;
    long long m=b;
    long long x=c;
    long long y=d;
    assert(n>0 and n<=(int)1e9);
    assert(m>0 and m<=(int)1e9);
    assert(x>0 and x<=(int)1e9);
    assert(y>0 and y<=(int)1e9);
    long long left = 0, right = n;
    while (left != right) {
        long long  mid = (left + right + 1) / 2;
        if (m + (n - mid) * y >= mid * x) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int main() {
    int res;
    int _n;
    cin >> _n;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    int _m;
    cin >> _m;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    int _x;
    cin >> _x;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    int _y;
    cin >> _y;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    res = toChocolate(_n, _m, _x, _y);
    cout << res << endl;
    
    return 0;
}
