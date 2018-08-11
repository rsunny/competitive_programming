
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

int max_size(vector < int > arr, int m) {
    int k=m;
    int n=arr.size();
    assert(n>=1 and n<=100000);
    assert(m>=1 and m<=100000);
    for(int i=0;i<n;i++){
        assert(arr[i]>=1 and arr[i]<=3000000);
        if(i)
            assert(arr[i]>arr[i-1]);
    }

    int left = 0, right = 0;
    int best = k;
    
    do {
        while ((arr[right] - arr[left]) - (right - left) > k) {
            ++left;
        }
        best = max(best, right - left + 1 + k);
        right += 1;
    } while (right < n);
    
    return best;
}

int main() {
    int res;
    
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
    
    int _m;
    cin >> _m;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    res = max_size(_arr, _m);
    cout << res << endl;
    
    return 0;
}
