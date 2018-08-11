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

vector<int>p;
int n;

inline bool check(long long int init){
	for(int i=0;i<n;i++){
		init+=p[i];
		if(init<=0)
			return 0;
	}
	return 1;
}

long min_health(vector < int > a) {
	n=a.size();
	assert(n>0 and n<=100000);
	for(int i=0;i<n;i++){
		assert(a[i]>=-1000000 and a[i]<=1000000);
		p.push_back(a[i]);
	}

	long long int lo = 0,hi = 1000000000000,mid,ans=0;
	while(lo<=hi){
		mid = (lo+hi)/2;
		if(check(mid)){
			if(!check(mid-1)){
				ans=mid;
				break;
			}
			else hi = mid-1;
		}
		else{
			if(check(mid+1)){
				ans = mid+1;
				break;
			}
			lo = mid+1;
		}
	}
	mid=ans;
	for(int i=-2;i<=2;i++)
		if(mid-i>0 and check(mid-i)){
			ans=mid;
			break;
		}
	return ans;
}

int main() {
    long res;
    
    int _a_size = 0;
    cin >> _a_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _a;
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _a.push_back(_a_item);
    }
    
    res = min_health(_a);
    cout << res;
    
    return 0;
}
