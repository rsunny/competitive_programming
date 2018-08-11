#include <iostream>
#include <vector>
#include <string.h>
#include <unordered_map>
#include <stdio.h>

using namespace std;

int MOD =1000000007;

long long fact[5001], invfact[5001];
char str[5001];
int t,q,n,k;
int freq[5005];
unordered_map<string,bool> m;

long long powmod(long long base, long long expo) {
	if(expo == 0)
		return 1;
	else if(expo & 1)
		return base * powmod(base, expo - 1) % MOD;
	else{
		long long root = powmod(base, expo >> 1);
		return root * root % MOD;
	}
}

long long inverse(long long x){
	return powmod(x, MOD - 2);
}

void init() {
	fact[0] = 1;
	for(int i = 1; i <= 5000; i++)
		fact[i] = i * fact[i - 1] % MOD;
	invfact[5000] = inverse(fact[5000]);
	for(int i = 5000; i > 0; i--)
		invfact[i - 1] = i * invfact[i] % MOD;
}

long long nCr(long long n, long long r){
	if(r > n || r < 0)
		return 0;
	return (fact[n] * invfact[r] % MOD) * invfact[n-r] % MOD;
}

int main(){
	init();
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&q);
		getchar();
		for(int i=0;i<n;i++){
			scanf("%c",&str[i]);
		}
		for(int i=0;i<n;i++){
			string s;
			for(int j=i;j<n;j++){
				s+=str[j];
				if(m.count(s)==0)
					freq[(int)s.size()]++;
			}
		}
	}
	return 0;
}