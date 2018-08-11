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

// /*
//  * Complete the function below.
//  */

// #include <cassert>

// int check(int n, string game, char ch){
//   string s = " ";
//   s[0]=ch;

//   s+=game;

//   s+=" "; n=s.size(); s[n-1]=ch;

//   int last=0;
//   int jump=0;
//   for(int i=1;i<(int)s.size();i++){
//     if(s[i]==ch){
//       jump=max(jump,i-last);
//       last=i;
//     }
//   }
//   return jump;
// }

// int power_jump(int n, string game) {
//   assert(n>0 and n<=100000);
//   int sz = game.size();
//   assert(n==sz);
//   for(int i=0;i<n;i++)
//     assert(game[i]=='0' or game[i]=='1');
//   return min(check(n,game,'0'),check(n,game,'1'));
// }

/*
 * Complete the function below.
 */
#include <assert.h>
int power_jump(int n, string game) {
    assert(n >= 1 && n <= 100000);
    int ret = 1;
    int lst = 0;
    for(int i=1;i<game.size();i++){
        assert(game[i] == '0' || game[i] == '1');
        if(game[i] == '0'){
            ret = max(ret, i - lst);
            lst = i;
        }
    }

    ret = max(ret, (int)game.size() - lst);

    lst = 0;
    int ret2 = 1;
    for(int i=1;i<game.size();i++){
        if(game[i] == '1'){
            ret2 = max(ret2, i - lst);
            lst = i;
        }
    }

    ret2 = max(ret2, (int)game.size() - lst);

    return min(ret, ret2);
}

int main() {
    int res;
    int _n;
    cin >> _n;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    string _game;
    getline(cin, _game);
    
    res = power_jump(_n, _game);
    cout << res << endl;
    
    return 0;
}
