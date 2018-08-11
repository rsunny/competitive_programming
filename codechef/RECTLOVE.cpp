#include <iostream>
#include <string.h>
#include <iomanip>
#include <stdio.h>

using namespace std;

int main(){
	int t,K,n,m;
	long long int ele;
	cin>>t;
	while(t--){
		cin>>n>>m>>K;
		long double ans = 0;
		long double a,b,c,d,e,f,g,h;
		e=n,f=m,g=n+1,h=m+1;
		for(int l=0;l<K;l++){
			cin>>ele;
			long long int i=ele/m; i+= (ele%m!=0); a=i; d=g-a;
			long long int j=ele%m; j = (!j)?m:j; b=j; c=h-b;
			ans+=(a/e)*(b/f)*(c/g)*(d/h);
		}
		ans*=4.0;
		printf("%.10Lf\n", ans);
	}
	return 0;
}