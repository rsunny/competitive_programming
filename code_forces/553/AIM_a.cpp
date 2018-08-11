#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	double w,l,v1,v2;
	double z=0;
	cin>>w>>l>>v1>>v2;
	cout <<setprecision(9)<<max(z,(l-w)/(v1+v2))<<"\n";
	return 0;
}