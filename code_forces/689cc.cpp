#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

long long int m;

long long int func(long long int n){
	long long int num;
	long long int cnt=0;
	for(int i=2;i<=1e6;i++){
		num=i;
		num=num*num*num;
		if(num<=n)
			cnt+=n/num;
	}
	return cnt;
}

int main(){
	cin>>m;
	long long int lo=8;
	long long int hi=1e18;
	while(lo<hi){
		long long int mid=hi+lo;
		mid/=2LL;
		if(func(mid)>=m)
			hi=mid;
		else
			lo=mid+1;
	}
	if(func(hi)==m)
		cout<<hi<<"\n";
	else
		cout<<"-1\n";
	return 0;
}
