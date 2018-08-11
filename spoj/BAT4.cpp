#include <iostream>
#include <string.h>
#include <cassert>
#include <algorithm>

using namespace std;

int dp_up[25][25],dp_time[25][25];
int arr[25][25];
int n,tme;

int main(){
	int t;
	cin>>t;
	while(t--){
		memset(dp_up,-1,sizeof dp_up);
		memset(dp_time,-1,sizeof dp_time);
		cin>>n>>tme;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				cin>>arr[i][j];
		dp_time[1][1]=tme-arr[1][1];
		dp_up[1][1]=arr[1][1];
		int pi,pj;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				pi=-1,pj=-1;
				if(i==1 and j>1){
					if(dp_time[i][j-1]>=abs(arr[i][j-1]-arr[i][j]))
 	 	 				pi=i,pj=j-1;
				}
				else if(i>1 and j==1){
 	 	 			if(dp_time[i-1][j]>=abs(arr[i-1][j]-arr[i][j]))
 	 	 				pi=i-1,pj=j;
				}
				else if(max(dp_up[i-1][j],arr[i][j]-arr[i-1][j])<max(dp_up[i][j-1],arr[i][j]-arr[i][j-1])){
 	 	 			if(dp_time[i-1][j]>=abs(arr[i-1][j]-arr[i][j]))
 	 	 				pi=i-1,pj=j;
 	 	 			else if(dp_time[i][j-1]>=abs(arr[i][j-1]-arr[i][j]))
 	 	 				pi=i,pj=j-1;
				}
				else if(max(dp_up[i-1][j],arr[i][j]-arr[i-1][j])>max(dp_up[i][j-1],arr[i][j]-arr[i][j-1])){
 	 	 			if(dp_time[i][j-1]>=abs(arr[i][j-1]-arr[i][j]))
 	 	 				pi=i,pj=j-1;
 	 	 			else if(dp_time[i-1][j]>=abs(arr[i-1][j]-arr[i][j]))
 	 	 				pi=i-1,pj=j;
				}
				else if(max(dp_up[i-1][j],arr[i][j]-arr[i-1][j])==max(dp_up[i][j-1],arr[i][j]-arr[i][j-1])){
					if(dp_time[i][j-1]>=abs(arr[i][j-1]-arr[i][j]) and dp_time[i-1][j]>=abs(arr[i-1][j]-arr[i][j])){
						if(dp_time[i-1][j]-abs(arr[i][j]-arr[i-1][j])>dp_time[i][j-1]-abs(arr[i][j]-arr[i][j-1])){
							pi=i-1;pj=j;
						}
						else{
							pi=i;pj=j-1;
						}
					}
 	 	 			else if(dp_time[i][j-1]>=abs(arr[i][j-1]-arr[i][j]))
 	 	 				pi=i,pj=j-1;
 	 	 			else if(dp_time[i-1][j]>=abs(arr[i-1][j]-arr[i][j]))
 	 	 				pi=i-1,pj=j;
				}
				if(pi!=-1 and pj!=-1){
					dp_up[i][j]=max(dp_up[pi][pj],arr[i][j]-arr[pi][pj]);
					dp_time[i][j]=dp_time[pi][pj]-abs(arr[i][j]-arr[pi][pj]);
				}
			}
		}

		if(dp_up[n][n]==-1){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES : ";
		cout<<dp_up[n][n]<<" "<<dp_time[n][n]<<"\n";
	}
	return 0;
}