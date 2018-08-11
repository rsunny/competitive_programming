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
	int n,t,l,r;
	cin>>t;
	while(t--){
		int res=INT_MAX;
		cin>>n>>l>>r;
		int k=abs(l-r);
		ll ans=0;
		int temp=k;
		for(int i=0;;i++){
			ans+=i;
			if(ans-k>=0 and (ans-k)%2==0){
				res=min(res,i);
				break;
			}
		}
		k=n-k;
		ans=0;
		for(int i=0;;i++){
			ans+=i;
			if(ans-k>=0 and (ans-k)%2==0){
				res=min(res,i);
				break;
			}
		}
		k=temp;
		cout<<res<<endl;
	}
	return 0;
}