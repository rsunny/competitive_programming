#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

int main(){
	int n,d;
	string s;
	scanf("%d %d",&n,&d);
	int prev=0;
	int res=0;
	int cnt;
	for(int i=0;i<d;i++){
		cin>>s;
		cnt=0;
		for(int j=0;j<n;j++)
			if((s[j]-'0')==1)
				cnt++;
		if(cnt!=n)
			prev++;
		else
			prev=0;
		res=max(res,prev);
	}
	cout<<res<<"\n";
	return 0;
}
