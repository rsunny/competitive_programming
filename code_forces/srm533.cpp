#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

using namespace std;
 
vector<int> v;
int n;
int dp[55][55];

int doit(int l,int r){
  if(l+1==r)
    return 0;
  if(dp[l][r]!=-1)
    return dp[l][r];
  int res=0;
  for(int i=l+1;i<r;i++)
    res=max(res,doit(l,i)+doit(i,r));
  res+=(v[l]*v[r]);
  dp[l][r]=res;
  return res;
}

class CasketOfStar {
public:
  int maxEnergy(vector <int> arr){
    v.push_back(1);
    n=arr.size();
    for(int i=0;i<n;i++)
      v.push_back(arr[i]);
    v.push_back(1);
    n=v.size();
    memset(dp,-1,sizeof dp);
    return doit(0,n-1);
  }
};
 