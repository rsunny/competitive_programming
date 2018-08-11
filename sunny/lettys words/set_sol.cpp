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

bool IsSubsequence(string a, string b) {
    if ((int)a.size() + 1 != (int)b.size()) {
        return false;
    }    
    int i = 0, j = 0;
    for (; i < (int)a.size(); ++ i) {
        while (j < (int)b.size() && a[i] != b[j]) {
            j ++;
        }
        if (j == (int)b.size()) {
            return false;
        }
        j ++;
    }
    return true;
}

int find_all(string s, vector < string > words) {
    int n=s.size();
    assert(n>=1 and n<=100);
    for(int i=0;i<n;i++)
        assert(s[i]>='a' and s[i]<='z');
    n=words.size();
    assert(n>=1 and n<=10000);
    for(int i=0;i<(int)words.size();i++){
        n=words[i].size();
        assert(n>=1 and n<=100);
        for(int j=0;j<n;j++)
            assert(words[i][j]>='a' and words[i][j]<='z');
    }

    n=words.size();
    
    int ans = 0;
    for (int i = 0; i < n; ++ i) {
        if (s == words[i] or IsSubsequence(s, words[i]) or IsSubsequence(words[i], s))
            ans ++;
    }
    return ans;
}

int main() {
    int res;
    string _s;
    getline(cin, _s);
    
    
    int _words_size = 0;
    cin >> _words_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<string> _words;
    string _words_item;
    for(int _words_i=0; _words_i<_words_size; _words_i++) {
        getline(cin, _words_item);
        _words.push_back(_words_item);
    }
    
    res = find_all(_s, _words);
    cout << res << endl;
    
    return 0;
}
