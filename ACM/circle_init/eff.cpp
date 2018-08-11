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
	int n,temp,lo,hi,res;
	long long int mid,ans;
	cin>>n;
	for(int k=0;k<n;k++){
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
		printf("%d %d\n",temp,res);
		k=temp;
	}
	return 0;
}