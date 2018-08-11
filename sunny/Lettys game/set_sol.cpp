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

int game(int n, int x) {
    if ( n == 1 )
        return 1 ;
    if ( x % 2 )
        return n / 2 + game ( ( n + 1 ) / 2, ( x + 1 ) / 2 ) ;
    return game ( n / 2, x / 2 ) ;
}

int main() {
    int res;
    int _n;
    cin >> _n;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    int _x;
    cin >> _x;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    assert(n>=1 and n<=10000000);
    assert(x>=1 and x<=10000000 and x<=n);
    res = game(_n, _x);
    cout << res << endl;
    
    return 0;
}
