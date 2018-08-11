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

vector < int > candies(vector < int > arr, int m) {
    set <int> st;
    sort(arr.begin(), arr.end());
    int n=arr.size();
    for(int i = 0 ; i < arr.size(); i++){
        st.insert(arr[i]);
    }
    assert(n==(int)st.size());
    assert(m>=1 and m<=1000000000);

    vector <int> ret;
    
    for(int i=1;;i++){
        if(i > m ) break;
        if(st.find(i) == st.end()){
            m -= i;
            ret.push_back(i);
        }
    }

    return ret;
}

int main() {
    vector < int > res;
    
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
    
    res = candies(_arr, _m);
    for(int res_i=0; res_i < res.size(); res_i++) {
        cout << res[res_i] << endl;;
    }
    
    return 0;
}
