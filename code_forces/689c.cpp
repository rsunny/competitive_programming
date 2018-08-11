#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

int arr[1000];

long long int m;

int main(){
	int n;
	for(int i=1;i<=1000000;i++){
		n=i;
		int cnt=0;
		for(int j=1;;j++){
			int ct=0;
			for(int k=2;;k++){
				if(j*k*k*k<=n)
					ct++;
				else
					break;
			}
			if(ct==0)
				break;
			cnt+=ct;
		}
		//cout<<n<<" "<<cnt<<"\n";
		if(cnt*100<n)
			cout<<n<<" "<<cnt<<"\n";
		//arr[cnt]++;
	}
	// for(int i=0;i<1000;i++)
	// 	if(arr[i]!=arr[i+1])
	// 		cout<<i<<" "<<arr[i]<<"\n";
	// cout<<"\n";
	cin>>m;
	long long int lo=1;
	long long int hi=1e18;
	while(lo<=hi){
		long long int mid=hi+lo;
		mid/=2LL;
		if(func(mid))
	}
	return 0;
}
