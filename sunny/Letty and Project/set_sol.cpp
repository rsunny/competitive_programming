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
int max_streak(int m, vector < string > data) {
    int d=data.size();
    int prev=0;
    int res=0;
    int cnt;
    assert(d>0 and d<=100000);
    assert(m>0 and m<=10);
    for(int i=0;i<d;i++){
        cnt=0;
        assert((int)data[i].size()==m);
        for(int j=0;j<m;j++){
            assert(data[i][j]=='Y' or data[i][j]=='N');
            if(data[i][j]=='Y')
                cnt++;
        }
        if(cnt==m)
            prev++;
        else
            prev=0;
        res=max(res,prev);
    }
    return res;
}

int main() {
    int res;
    int _m;
    cin >> _m;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    
    int _data_size = 0;
    cin >> _data_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<string> _data;
    string _data_item;
    for(int _data_i=0; _data_i<_data_size; _data_i++) {
        getline(cin, _data_item);
        _data.push_back(_data_item);
    }
    
    res = max_streak(_m, _data);
    cout << res << endl;
    
    return 0;
}
