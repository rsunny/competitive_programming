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
	int n;
	cin>>n;
	for(int k=0;k<n;k++){
		ll ans=0;
		int temp=k;
		k=min(k,n-k);
		for(int i=0;;i++){
			ans+=i;
			if(ans-k>=0 and (ans-k)%2==0){
				cout<<temp<<" "<<i<<endl;
				break;
			}
		}
		k=temp;
	}
	return 0;
}