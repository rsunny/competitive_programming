#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

string Y="Yes";
string N="No";

int main(){
	int t;
	scanf("%d",&t);
	for(int test=1;test<=t;test++){
		int n,ce;
		vector<int> c;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			cin>>ce,c.push_back(ce);
		int flag=0;
		for(int i=0;i<n;i++)
			if(i+2<n and c[i]==c[i+1] and c[i+1]==c[i+2])
				flag=1;
		string res=(flag==1)?Y:N;
		cout<<res<<"\n";
	}
	return 0;
}
