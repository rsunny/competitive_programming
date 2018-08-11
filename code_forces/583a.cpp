#include <iostream>

using namespace std;

int r[55][2];

int main(){
	int n;
	cin>>n;
	int a,b;
	for(int i=1;i<=n*n;i++){
		cin>>a>>b;
		if(r[a][0]==0 and r[b][1]==0){
			cout<<i<<"\n";
			r[a][0]=1;
			r[b][1]=1;
		}
	}
	return 0;
}