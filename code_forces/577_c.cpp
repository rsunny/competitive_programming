#include <iostream>
#include <vector>
#include <cstdio>
#include <string.h>
#include <set>

using namespace std;

#define MAX_N 1005
int n;
int isprime[MAX_N];
vector<int> pr;
set<int> v;

void pre(){
    memset(isprime,0,sizeof isprime);
    
    for(int i=2;i<MAX_N;i++)
    {
        if(isprime[i]==0)
        {
            isprime[i]=i;
            pr.push_back(i);
        }
        for(int j=0;j<(int)pr.size() and pr[j]<=isprime[i] and i*pr[j]<MAX_N;j++)
            isprime[i*pr[j]] = pr[j];
    }
     
}


int main(){
	cin>>n;
	pre();
	for(int i=0;i<(int)pr.size();i++){
		int val=pr[i];
		while(val<=n){
			v.insert(val);
			val*=pr[i];
		}
	}
	cout<<v.size()<<"\n";
	set<int> :: iterator it;
	for(it=v.begin();it!=v.end();it++)
		cout<<*it<<" ";
	cout<<"\n";
	return 0;
}