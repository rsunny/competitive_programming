#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <cmath>

using namespace std;

int main(){
	int n;
	long double a,b;
	cin>>a>>b;
	scanf("%d",&n);
	long double ans=1e9;
	for(int i=0;i<n;i++){
		long double x,y,z;
		cin>>x>>y>>z;
		long double xx=(x-a)*(x-a);
		long double yy=(y-b)*(y-b);
		long double dist = sqrt(xx+yy);
		long double v=z;
		long double t=dist/v;
		ans=min(ans,t);
	}
	printf("%.9lf\n",(double)ans);
	return 0;
}
