#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

long long int bt[100005];
long long int sum;

int main(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>bt[i];
		sum+=bt[i];
	}
	int c;
	long long int sol=0;
	for(int i=0;i<k;i++){
		cin>>c;
		sum-=bt[c];
		sol+=bt[c]*sum;
		bt[c]=0;
	}
	bt[n+1]=bt[1];
	for(int i=1;i<=n;i++){
		sol+=(bt[i]*bt[i+1]);
	}
	cout<<sol<<"\n";
	return 0;
}

