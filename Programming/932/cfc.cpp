#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int main(){
	int n,a,b;
	int g1=-1,g2=-1;

	cin>>n>>a>>b;

	for(int i=0;i*a<=n;i++){
		int x=a*i;
		if((n-x)%b==0){
			g1=i,g2=(n-x)/b;
			break;
		}
	}
	
	if(g1==-1){
		cout<<"-1\n";
		return 0;
	}

	int cnt=1;
	
	for(int i=0;i<g1;i++){
		printf("%d ", cnt+a-1);
		for(int j=1;j<a;j++){
			printf("%d ",cnt);
			cnt++;
		}
		cnt++;
	}	

	for(int i=0;i<g2;i++){
		printf("%d ", cnt+b-1);
		for(int j=1;j<b;j++){
			printf("%d ",cnt);
			cnt++;
		}
		cnt++;
	}

	cout<<"\n";
	return 0;
}