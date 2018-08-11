#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
	double a,b,x;
	cin>>a>>b;
	if(a==b){
		cout<<a<<"\n";
		return 0;
	}
	double res1=-1;
	if(a>b){
		x=a-b;
		double cnt=1;
		while((x/cnt)>=b)
			res1=x/cnt,cnt++;
	}
	x=a+b;
	double res2=-1;
	double cnt=2;
	while((x/cnt)>b)
		res2=x/cnt,cnt++;
	if(res1==-1)
		cout<<res2<<"\n";
	else if(res2==-1)
		cout<<res1<<"\n";
	else cout<<min(res1,res2)<<"\n";
	return 0;
}