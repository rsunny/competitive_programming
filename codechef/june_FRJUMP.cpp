#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <cmath>

using namespace std;

int n;
int arr[100009];
double logten[100009];
int mod=(1e9)+7;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>arr[i],logten[i]=log10(arr[i]);
	int q;
	int c,r;
	long long int f;
	cin>>q;
	while(q--){
		scanf("%d %d",&c,&r);
		if(c==1){
			scanf("%lld",&f);
			arr[r]=f;
			logten[r]=log10(f);
		}	
		else{
			long long int res=1;
			double ans=0;
			for(int i=0;1+(r*i)<=n;i++){
				res*=arr[1+(r*i)],res%=mod;
				ans+=log10(arr[1+(r*i)]);
			}
			int fir=floor(powf(10, ans - floor(ans+1e-9))+1e-9);
			printf("%d %lld\n",fir,res);
		}
	}
	return 0;
}