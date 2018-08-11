#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

int main(){
	int t;
	int k=0;
	// int res=0,cnt=0;	
	// int ele;	
	scanf("%d",&t);
	for(int test=1;test<=t;test++){
		scanf("%d",&k);
		vector<int> num[20];
		string bin="";
		while(k){
			bin+=(k%2)?"1":"0";
			k/=2;
		}
		reverse(bin.begin(),bin.end());
		int n=bin.size();
		int N=1;
		for(int l=0;l<n-1;l++){
			num[l].push_back(N);
			num[l].push_back(N+1);
			N+=2;
		}
		int maxn;
		for(int i=1;i<n;i++){
			if(bin[i]=='0')
				continue;
			if(i<n-1)
				maxn=num[i][0];
			else
				maxn=N;
			for(int l=max(i-1,1)-1;l>=0;l--){
				num[0].push_back(maxn+l);
				N++;
			}
			for(int l=0;l<n-1;l++){
				if(num[l][0]>=maxn or num[l][1]>=maxn)
					num[l][0]+=max(i-1,1),num[l][1]+=max(i-1,1);
			}
		}
		//cout<<test<<" "<<N-1<<"\n";
		for(int i=0;i<n-1;i++)
			for(int j=num[i].size()-1;j>=0;j--)
				cout<<num[i][j]<<" ";
		cout<<"\n";
		// if(res<N)
		// 	res=N,ele=test;
		// if(N>100)
		// 	cnt++;
	}
	//cout<<res<<" "<<ele<<" "<<cnt<<"\n";
	return 0;
}
