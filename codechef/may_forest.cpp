#include <iostream>
#include <algorithm>

using namespace std;

long long int h[100009];
long long int r[100009];
int n;
long long int w,l;

bool func(long long m){
	long long int tot=0,mul;
	for(int i=0;i<n;i++){
		mul=r[i]*m;
		mul+=h[i];
		if(mul>=l)
			tot+=mul;
		if(tot>=w)
			return true;
	}
	return false;
}

int main(){
	cin>>n>>w>>l;
	long long int low=0,high=1e18,mid,ans=1e18;
	for(int i=0;i<n;i++)
		cin>>h[i]>>r[i];
	while(high>=low){
		mid=low+((high-low)/2);
		if(func(mid)){
			ans=min(ans,mid);
			high=mid-1;
		}
		else
			low=mid+1;
	}
	cout<<ans<<"\n";
	return 0;
}