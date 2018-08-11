#include <iostream>

using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int res=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int a,b;
			cin>>a>>b;
			if(a or b)
				res++;
		}
	}
	cout<<res<<"\n";
	return 0;
}