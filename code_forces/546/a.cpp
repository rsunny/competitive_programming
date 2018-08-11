#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <cstdio>

using namespace std;

int main(){
	int k,w,n;
	cin>>k>>n>>w;
	int d=0;
	for(int i=1;i<=w;i++)
		d+=(i*k);
	d=max(0,d-n);
	cout<<d<<"\n";
	return 0;
}