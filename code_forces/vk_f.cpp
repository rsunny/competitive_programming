#include <iostream>
#include <vector>
#include <cstdio>
#include <string.h>

using namespace std;

#define MAX_N 1000009

int isprime[MAX_N];
vector<int> pr;
int arr[MAX_N];
int n;
int max_lmt;

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

int main(){
	scanf("%d",&n);
	int plus=0;
	for(int i=0;i<n;i++){
		int e;
		scanf("%d",&e);
		max_lmt=max(e,max_lmt);
		arr[e]=1;
		if(e==1)
			plus=1;
	}
	pre();
	int res=0;
	for(int i=2;i<=max_lmt;i++){
		int cnt=0;
		for(int j=0;pr[j]*pr[j]<=i;j++){
			if(i%pr[j]==0){
				cnt=max(cnt,arr[i/pr[j]]);
				int other=i/pr[j];
				if(isprime[other]==other){
					cnt=max(cnt,arr[i/other]);
				}
			}
		}
		arr[i]+=cnt;
		res=max(res,arr[i]);
	}
	cout<<res+plus<<"\n";
	return 0;
}
