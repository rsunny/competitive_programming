#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <unordered_map>
#include <cassert>

using namespace std;

#define MAXN (1<<21)

int n;
int doo[MAXN+100][50];
long long int dp[MAXN+100];
unordered_map<int,bool> s;
int temp;

void doit(int mask){
	//cout<<mask<<" "<<__builtin_popcount(mask)<<"\n";;
	//s[mask]=true;
	dp[mask]=true;
	for(int i=1;i<=n;i++){
		if(!(mask&(1<<i)))
		for(int j=1;j<=n;j++){
			if(i!=j and !(mask&(1<<j)))
			for(int k=1;k<=n;k++){
				if(i!=k and j!=k and !(mask&(1<<k)))
				for(int l=1;l<=n;l++){
					if(k!=l and i!=l and j!=l and !(mask&(1<<l)) and !dp[mask|(1<<i)|(1<<j)|(1<<k)|(1<<l)]){
						//cout<<i<<" "<<j<<" "<<k<<" "<<l<<"\n";
						//cin>>temp;
						doit(mask|(1<<i)|(1<<j)|(1<<k)|(1<<l));
					}
				}
			}
		}
	}
	return ;
}

int main(){
	assert((int)sizeof doo <= (int)(5.12e+8));
	n=20;
	//doit(0);
	cout<<(1<<n)<<"\n";
	cout<<s.size()<<"\n";
	return 0;
}