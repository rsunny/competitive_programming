#include <iostream>

using namespace std;

unsigned long long int arr[50];

int main(){
	unsigned long long int a,b,c=1,d;
	int bt1=0,bt2=0;
	cin>>a>>b;
	d=b;
	while(d){
		bt2++;
		d/=2;
	}
	d=a;
	while(d){
		bt1++;
		d/=2;
	}
	arr[1]=1;
	for(int i=2;i<=64;i++)
		c*=2LL,arr[i]=c;
	int res=0;
	for(int j=bt1;j<=bt2;j++){
		c=0;
		for(int i=0;i<=j;i++)
			c+=arr[i];
		for(int i=1;i<j;i++){
			d=c-arr[i];
			if(d>=a and d<=b)
				res++;
		}
	}
	cout<<res<<"\n";
	return 0;
}