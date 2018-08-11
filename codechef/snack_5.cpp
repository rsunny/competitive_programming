#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

int mod=1000000007;

int main(){
	int t;
	int temp;
	scanf("%d",&t);
	for(int test=1;test<=t;test++){
		int n,m,x,y;
		int sum=0;
		scanf("%d %d %d %d",&n,&m,&x,&y);
		vector<int> arr[2];
		for(int i=0;i<n;i++){
			scanf("%d",&temp);
			arr[0].push_back(temp);
		}	
		while(m--){
			arr[1].push_back(arr[0][0]);
			for(int i=1;i<(int)arr[0].size();i++){
				arr[1].push_back(arr[0][i-1]+arr[0][i]);
				arr[1].push_back(arr[0][i]);
			}
			arr[0]=arr[1];
			arr[1].clear();
		}
		n=arr[0].size();
		for(int i=x-1;i<y;i++){
			sum+=arr[0][i];
			sum%=mod;
		}
		cout<<sum<<"\n";
	}
	return 0;
}
