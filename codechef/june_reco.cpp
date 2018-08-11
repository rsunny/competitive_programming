#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <cmath>
#include <cassert>

using namespace std;

long long int n,ele;
long long int arr[100009];
vector<double> logten;
vector<long long int> mul;
vector<int> mp[100009];
long long int mod=(1e9)+7;

long long int modular_inverse(long long int base,long long int exponent){
   long long int result = 1;
   while(exponent>0){
       if (exponent%2==1)
           result=(result*base)%mod;
       exponent=exponent>>1;
       base=(base*base)%mod;
   }
   result%=mod;
   return result;
}


int main(){
	long long int res;
	double ans;

	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&arr[i]);

	logten.push_back(log10(arr[1]));
	mul.push_back(arr[1]);
	
	for(long long int i=1;i<=n;i++){
		res=1LL;
		ans=0.0;
		for(long long int j=1;(1+(j*i))<=n;j++){
			mp[1+(i*j)].push_back(i);
			res=(res*arr[1+(i*j)])%mod;
			ans+=(double)(log10(arr[1+(i*j)])*1.0);
		}
		mul.push_back(res);
		logten.push_back(ans);
	}
	int q,c,r;
	long long int f;
	scanf("%d",&q);

	while(q--){
		scanf("%d %d",&c,&r);
		if(c==1){
			scanf("%lld",&f);
			if(r==1)
				mul[0]=f,logten[0]=log10(f);
			else{
				long long int mod_inv=modular_inverse(arr[r],mod-2);
				for(int i=0;i<(int)mp[r].size();i++){
					ele=mp[r][i];
					logten[ele]+=(log10(f)-log10(arr[r]));
					res=mul[ele];
					res=(res*f)%mod;
					res=(res*mod_inv)%mod;
					mul[ele]=res;
				}
				arr[r]=f;
			}
		}	
		else{
			res=mul[0]*mul[r];	res%=mod;
			ans=logten[0]+logten[r];
			int fir=floor(pow(10, ans - floor(ans+1e-9))+1e-9);
			printf("%d %lld\n",fir,res);
		}
	}
	return 0;
}
