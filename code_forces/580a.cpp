#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
	int n,pele=-1,ele;
	cin>>n;
	int maxi=0,cnt=0;
	for(int i=0;i<n;i++){
		scanf("%d",&ele);
		if(pele>ele)
			maxi=max(maxi,cnt),cnt=0;
		cnt++;
		pele=ele;
	}
	maxi=max(maxi,cnt);
	cout<<maxi<<"\n";
	return 0;
}