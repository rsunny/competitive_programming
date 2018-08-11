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

vector<pair<int,int> > res;

vector < int > sorting(vector < int > arr) {
    vector<int> v=arr;
    int n=v.size();
    assert(n>=1 and n<=100000);
    for(int i=0;i<n;i++){
    	assert(arr[i]>=1 and arr[i]<=1000000);
    	int bit = __builtin_popcount(arr[i]);
    	res.push_back(make_pair(bit,arr[i]));
    }
    arr.clear();
    sort(res.begin(), res.end());
    for(int i=0;i<n;i++)
    	arr.push_back(res[i].second);
    return arr;
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
    
    res = sorting(_arr);
    for(int res_i=0; res_i < res.size(); res_i++) {
    	cout << res[res_i] << endl;;
    }
    
    return 0;
}