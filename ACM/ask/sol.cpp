#include <iostream>

using namespace std;

int arr[21];

void prime(int num){
	for(int i=2;i*i<=num;i++){
		if(num%i==0){
			int cnt=0;
			cout<<i<<" ";
			while(num%i==0)
				num/=i,cnt++;
			cout<<cnt<<"\n";
		}
	}
	if(num!=1)
		cout<<num<<" 1\n";
	cout<<"----------\n";
	return ;
}

int main(){
	int n;
	n=10;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	for(int i=0;i<(1<<n);i++){
		int temp=i;
		int g=1;
		for(int j=0;j<n;j++)
			if(temp&(1<<j))
				prime(arr[j]),g=arr[j];

		for(int j=0;j<n;j++)
			if(temp&(1<<j))
				g=__gcd(g,arr[j]);
		cout<<" gdc: "<<g<<"\n";
	}
	return 0;
}