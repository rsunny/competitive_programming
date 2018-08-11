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

#include <cassert>

/*
 * Complete the function below.
 */

map<char,int> cnt;
string glo="";

int check(string s,string g){
  int res = 0;
  string temp = "";

  for(int i=0;i<(int)s.size();i++)
  	for(int j=0;j<cnt[s[i]];j++)
  		temp+=s[i];
  for(int i=0;i<(int)g.size();i++)
  	res += (temp[i]!=g[i]);

  glo=g;
  return res/2;
}

int min_moves(int n, string g) {
  assert(n>0 and n<=100000);
  assert(n==(int)g.size());
  string s="abcd01";
  for(int i=0;i<n;i++){
    int f=0;
    for(int j=0;j<(int)s.size();j++){
      f|=(g[i]==s[j]);
    }
    assert(f==1);
  }

  for(int i=0;i<(int)s.size();i++){
    int c=0;
    for(int j=0;j<(int)g.size();j++){
      if(g[j]==s[i]){
        c++;
      }
    }
    cnt[s[i]]=c;
  }
  string ret="";
  sort(s.begin(),s.end());
  int res = check(s,g);
  do{
    res = min(res,check(s,g));
  }while(next_permutation(s.begin(),s.end()));
  return res;
}

int main() {
    int res;
    int _n;
    cin >> _n;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    string _game;
    getline(cin, _game);
    
    res = min_moves(_n, _game);
    cout << res << endl;
    
    return 0;
}
