#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;

int mod = 1e9 + 7;

long long int fast_exp(int base, int exp){
    if(exp==1)
    	return base;
    else{
        if(exp%2 == 0){
            long long int base1 = pow(fast_exp(base, exp/2),2);
            if(base1 >= mod)
            	return base1 % mod;
            else
            	return base1;
        }
        else{
            long long int ans = (base*  pow(fast_exp(base,(exp-1)/2),2));
            if(ans >= mod)
            	return ans % mod
            else
           		return ans;
        }
    }
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k;

	return 0;
}
