#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

#define MAX_N 33333500

int n=16,j=50;
int isprime[MAX_N];
vector<int> pr,v;
long long int mat[15][17];

void compute(){
	for(int i=2;i<=10;i++){
		long long int num=i;
		mat[i][0]=1;
		for(int j=1;j<=16;j++){
			mat[i][j]=mat[i][j-1]*num;
		}
	}
	return ;
}

void pre(){
    memset(isprime,0,sizeof isprime);
    for(int i=2;i<MAX_N;i++){
        if(isprime[i]==0){
            isprime[i]=i;
            pr.push_back(i);
        }
        for(int j=0;j<(int)pr.size() and pr[j]<=isprime[i] and i*pr[j]<MAX_N;j++)
            isprime[i*pr[j]] = pr[j];
    }
	return ;
}

int divisor(long long a){
	for(int i=0;i<pr.size();i++){
		long long start = ceil(a/(pr[i]+0.0));
		if(start==1)
			start++;
		for(long long j = start;j*pr[i]<=a;j++){
			if((j*pr[i]-a)==0)
				return pr[i];
		}
	}
	return -1;
}

void check(string s){
	reverse(s.begin(),s.end());
	v.clear();
	long long int ans;
	int res;
	for(int i=2;i<=10;i++){
		ans=0;
		for(int j=0;j<n;j++){
			if(s[j]=='1')
				ans+=mat[i][j];
		}
		res = divisor(ans);
		if(res==-1)
			return ;
		v.push_back(res);
	}
	j--;
	reverse(s.begin(),s.end());
	cout<<s<<" ";
	for(int i=0;i<(int)v.size();i++)
		cout<<v[i]<<" ";
	cout<<"\n";
	return ;
}

void reco(string s){
	if(!j)
		return ;
	if((int)s.size()==n-1){
		s+="1";
		check(s);
		return ;
	}
	reco(s+"0");
	reco(s+"1");
	return ;
}

int main(){
	pre();	compute();
	int t=1;
	cin>>t;
	cin>>n>>j;
	string s="1";
	printf("Case #1: \n");
	reco(s);
	return 0;
}