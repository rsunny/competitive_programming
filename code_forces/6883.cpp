#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std;

vector<long long int> v;

int main(){
	int n;
	long long int a,k;
	cin>>n>>k;
	long long int gcd=-1;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a==k){
			cout<<"Yes\n";
			return 0;
		}
		v.push_back(a);
		if(gcd==-1)
			gcd=a;
		gcd=__gcd(gcd,a);
	}
	k*=gcd;
	long long int res=1;
	for(int i=0;i<n;i++){
		res*=v[i];
		if(res>k){
			cout<<"No\n";
			return 0;
		}
	}
	cout<<"Yes\n";
	return 0;
}
