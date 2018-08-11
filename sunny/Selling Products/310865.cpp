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

map<int,int> id;
vector<pair<int,int> >res; 

int deleteProducts(vector < int > ids, int m) {
    int n = ids.size();
    assert(n>0 and n<=100000);
    for(int i=0;i<n;i++){
        id[ids[i]]++;
        assert(ids[i]>=1 and ids[i]<=1000000);
    }
    assert(m>=1 and m<=1000000);
    for(map<int,int> :: iterator it = id.begin(); it!=id.end(); it++){
        res.push_back(make_pair(it->second, it->first));
    }
    sort(res.begin(), res.end());
    int ret = res.size();
    for(int i=0;i<(int)res.size();i++){
        m-=res[i].first;
        if(m>=0)
            ret--;
    }
    return ret;
}

int main() {
    int res;
    
    int _ids_size = 0;
    cin >> _ids_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _ids;
    int _ids_item;
    for(int _ids_i=0; _ids_i<_ids_size; _ids_i++) {
        cin >> _ids_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _ids.push_back(_ids_item);
    }
    
    int _m;
    cin >> _m;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    res = deleteProducts(_ids, _m);
    cout << res << endl;
    
    return 0;
}
