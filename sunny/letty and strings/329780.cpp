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

string perm;
int pos[100];

void getp() {
    for (int i = 0 ; i < (int)perm.size() ; ++i) {
        pos[perm[i] - 'a'] = i;
        pos[perm[i] - 'a' + 26] = i + 26;
    }
    return ;
}

inline int cmp_char(char c1, char c2) {
    int p1, p2;
    p1 = c1 - 'a';
    p2 = c2 - 'a';
    if (pos[p1] < pos[p2])
        return -1;
    if (pos[p1] > pos[p2])
        return 1;    
    return 0;
}

inline bool cmp_string(string s1, string s2) {
    int len = s1.size() < s2.size() ? s1.size() : s2.size();
    
    for (int i = 0 ; i < len ; ++i) {
        int k = cmp_char(s1[i], s2[i]);
        
        if (k == -1)
            return true;
        if (k == 1)
            return false;
    }
    
    return true;
}

string max_string(vector < string > arr, string s) {
    int n=arr.size();
    assert(n>0 and n<=20000);
    for(int i=0;i<n;i++){
        assert((int)arr[i].size()>0 and (int)arr[i].size()<=100);
        for(int j=0;j<(int)arr[i].size();j++)
            assert(arr[i][j]>='a' and arr[i][j]<='z');
    }
    perm=s;
    assert((int)s.size()==26);
    sort(s.begin(),s.end());
    for(int i=0;i<26;i++)
        assert((int)s[i]-(int)'a'==i);
    
    getp();
    sort(arr.begin(), arr.end(), cmp_string);
    return arr[n-1];
}

int main() {
    string res;
    
    int _arr_size = 0;
    cin >> _arr_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<string> _arr;
    string _arr_item;
    for(int _arr_i=0; _arr_i<_arr_size; _arr_i++) {
        getline(cin, _arr_item);
        _arr.push_back(_arr_item);
    }
    
    string _s;
    getline(cin, _s);
    
    res = max_string(_arr, _s);
    cout << res << endl;
    
    return 0;
}
