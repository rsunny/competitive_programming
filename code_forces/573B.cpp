#include <iostream>

using namespace std;

int n,idx;
int h[2][100005];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>h[0][i];
	int res=0;
	while(1){
		res++;
		for(int i=1;i<n;i++){
			if(h[idx][i]>0){
				h[idx^1][i]=min(h[idx][i-1],h[idx][i+1]);
			}
		}
		idx^=1;
	}
	return 0;
}