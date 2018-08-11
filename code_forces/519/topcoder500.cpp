#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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

bool dp[55][55][2555];
bool vis[55][55][2555];
vector<int> arr;
int n;
int req,need;

int doit(int pos,int took,int sum){
	if(took>need or sum>req)
		return false;
	if(pos==n)
		return (took==need and sum==req)?true:false;
	if(vis[pos][took][sum]==true)
		return dp[pos][took][sum];
	vis[pos][took][sum]=true;
	dp[pos][took][sum]=doit(pos+1,took+1,sum+arr[pos])|doit(pos+1,took,sum);
	return dp[pos][took][sum];
}

class FoxAndSouvenirTheNext {
public:
	string ableToSplit(vector <int> value) {
	    arr=value;
	    n=value.size();
	    //cout<<n<<"\n";
		memset(dp,false,sizeof dp);
		for(int i=0;i<n;i++)
			req+=value[i];
	    need=n/2;
	    if(req%2==1 or n%2==1)
	    	return "Impossible";
	    req/=2;
	    
		if (doit(0,0,0) == true)
     		return "Possible";
     	return "Impossible";
    }
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!