#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int func(int n,int m){
	if(m==0 or n==0)
		return 0;
	if(m==1 and n==1)
		return 0;
	if((n==1 and m>1) or (m==1 and n>1))
		return 1;
	int sec=m/2;
	int fir=n;
	int teams=min(sec,fir);
	n=n-teams;
	m=m-(2*teams);
	int res = func(n,m);
	res = max (res, func(m,n));
	return teams+res;
}

int main(){
	int cnt=0;
	while(1){
		int n,m;
		n=rand()%500000,m=rand()%50000,n++,m++;
		int res=func(n,m);
		res=max(res,func(m,n));
		if(res!=min(n,min(m,(n+m)/3))){
			cout<<n<<" - "<<m<<"\n";
			cnt++;
			if(cnt>10)
				return 0;
		}
	}
	return 0;
}