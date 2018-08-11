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
int M[105];

int min_count(vector < int > arr) {
    int n=arr.size();
    assert(n>=1 and n<=100000);
    for(int i=0;i<n;i++){
        assert(arr[i]>=1 and arr[i]<=100);
        M[arr[i]]++;
    }
    int res=0;
    int x;
    for(int i=1;i<=100;i++){
        if(!M[i])
            continue;
        x=M[i]/i;
        if(M[i]%i)
            x++;
        res+=(x*i);
    }
    return res;

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
    
    res = min_count(_arr);
    cout << res << endl;
    
    return 0;
}
