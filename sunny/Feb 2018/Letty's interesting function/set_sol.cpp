#include <iostream>
#include <vector>
#include <stdio.h>
#include <cassert>
#include <algorithm>

#define ll long long
using namespace std;

int s(long long int n) {
    int res = 0;
    while (n) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

long long int solve(long long int n) {
    assert(n >= 1LL );
    assert(n <= 1000000000000000LL);
    long long int res = -1;
    for (long long int i = max(0LL, n - 100); i <= n; ++i) {
        if(n - s(i) == i)
            res = max(res, i);
    }
    return res;
}

int main(){
    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long long int res = solve(n);

    cout << res << "\n";

    return 0;
}
