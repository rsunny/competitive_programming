#include <iostream>
#include <vector>
#include <cstdio>
#include <string.h>
#include <sstream>
using namespace std;

#define MAX_N 10000009

int isprime[MAX_N];
vector<int> pr;
int arr[MAX_N];
int n;
int max_lmt=1180455;
long long int primes[MAX_N];
long long int palin[MAX_N];

void pre(){
    for(int i=2;i<=max_lmt;i++){
        if(isprime[i]==0){
            isprime[i]=i;
            pr.push_back(i);
        }
        for(int j=0;j<(int)pr.size() and pr[j]<=isprime[i] and i*pr[j]<=max_lmt;j++)
            isprime[i*pr[j]] = pr[j];
    }
    return ;
}

long long int palindrome(int num){
	string s1,s2;
	stringstream ss;
	ss<<num;
	ss>>s1;
	s2=s1, reverse(s1.begin(), s1.end());
	return (s1==s2);
}

int main(){
	long long int p,q;
	cin>>p>>q;
	pre();
	int ans=0;
	int cnt=0;
	for(int i=1;i<=max_lmt;i++){
		primes[i]=primes[i-1]+(isprime[i]==i);
		palin[i]=palin[i-1]+palindrome(i);
		primes[0]=0;
		if(q*primes[i]<=p*palin[i])
			ans=i;
	}
	cout<<cnt<<"\n";
	cout<<ans<<"\n";
	return 0;
}