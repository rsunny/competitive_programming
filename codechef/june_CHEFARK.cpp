#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <cassert>

using namespace std;

long long int mod=(1e9)+7;
long long int fact[100009];
long long int ifact[100009];

long long int modular_inverse(long long int base,long long int exponent){
   long long int result = 1;
   while(exponent>0){
       if (exponent%2==1)
           result=(result*base)%mod;
       exponent=exponent>>1;
       base=(base*base)%mod;
   }
   return result;
}

int main(){
	int t,n,k,temp;
	int cnt;
	long long int res;
	scanf("%d",&t);
	fact[0]=1;
	ifact[0]=1;
	for(int i=1;i<=100000;i++){
		fact[i]=(fact[i-1]*i)%mod;
		ifact[i]=(modular_inverse(i,mod-2)*ifact[i-1])%mod;
	}
	for(int test=1;test<=t;test++){
		cnt=0;res=0;
		scanf("%d %d",&n,&k);
		for(int i=0;i<n;i++){
			scanf("%d",&temp);
			if(temp!=0)
				cnt++;
		}
		if(cnt==n){
			for(int i=(k%2)?1:0;i<=n and i<=k;i+=2){
				res+=(((fact[n]*ifact[i])%mod)*ifact[n-i])%mod;
				res%=mod;
			}
		}
		else{
			n=cnt;
			for(int i=0;i<=n and i<=k;i++){
				res+=(((fact[n]*ifact[i])%mod)*ifact[n-i])%mod;
				res%=mod;
			}
		}
		printf("%lld\n",res);
	}
	return 0;
}