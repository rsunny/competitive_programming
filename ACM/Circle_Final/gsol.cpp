#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <cstring>
#include <cmath>
#include <cassert>
#include <set>
#include <stack>
#include <algorithm>

#define pb push_back
#define mp make_pair
#define ll long long
#define fir first
#define sec second
#define MOD 1000000007

using namespace std;

int main(){	
	int t,k,n,temp,lo,hi,res;
	long long int mid,ans;
	cin>>t;
	assert(t>0 and t<=10000);
	while(t--){

		cin>>n>>lo>>hi;
		assert(n>0 and n<=1000000 and lo>=1 and lo<=n and hi>=1 and hi<=n);
		
		k=abs(hi-lo);

		temp=k;

		lo=0,hi=n+1;
		while(hi-lo>1){
			mid=lo+hi; mid/=2LL;
			if((mid*(mid+1)/2)>=k)
				hi=mid;
			else
				lo=mid;
		}
		while(true){
			ans=lo*(lo+1);ans/=2;
			if(ans-k>=0 and (ans-k)%2==0){
				break;
			}
			lo++;
		}
		res=lo;

		k=n-k;
		lo=0,hi=n+1;
		while(hi-lo>1){
			mid=lo+hi; mid/=2LL;
			if((mid*(mid+1)/2)>=k)
				hi=mid;
			else
				lo=mid;
		}
		while(true){
			ans=lo*(lo+1);ans/=2;
			if(ans-k>=0 and (ans-k)%2==0){
				break;
			}
			lo++;
		}
		res=min(res,lo);
		printf("%d\n",res);
		k=temp;
	}
	return 0;
}