#include <iostream>

using namespace std;

int main(){
	int n,x,res=0;
	cin>>n>>x;
	for(int i=1;i<=n;i++)
		if(x%i==0 and (x/i)<=n)
			res++;
	cout<<res<<"\n";
	return 0;
}