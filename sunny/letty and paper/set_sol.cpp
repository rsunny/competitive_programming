#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */

long long int MAX_N = 1000000000000000;

int solve(long h, long w, long h1, long w1) {
    int res=0;
    assert(h1>0 and h1<=MAX_N);
    assert(w1>0 and w1<=MAX_N);
    assert(h>0 and h<=MAX_N);
    assert(w>0 and w<=MAX_N);
    while(h1<h)
        res++,h=(h+1)/2;
    while(w1<w)
        res++,w=(w+1)/2;
    return res;
}

int main() {
    int res;
    long _h;
    cin >> _h;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    long _w;
    cin >> _w;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    long _h1;
    cin >> _h1;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    long _w1;
    cin >> _w1;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    res = solve(_h, _w, _h1, _w1);
    cout << res << endl;
    
    return 0;
}
