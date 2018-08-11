#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

int main(){
	int n,ele,q;
	scanf("%d",&n);
	scanf("%d",&q);
	int mini=1e9;
	int maxi=1;
	for(int i=0;i<n;i++){
		scanf("%d",&ele);
		mini=min(mini,ele);
		maxi=max(ele,maxi);
	}
	while(q--){
		scanf("%d",&ele);
		if(mini<=ele and maxi>=ele)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}
