#include <iostream> 
#include <algorithm>
#include <cstdio>

using namespace std;

int arr[100005];
int maxi[100005];

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	maxi[n-1]=arr[n];
	arr[n]=0;
	for(int i=n-1;i>=1;i--){
		if(maxi[i]<arr[i])
			maxi[i-1]=arr[i],arr[i]=0;
		else
			arr[i]=maxi[i]-arr[i]+1,maxi[i-1]=maxi[i];
	}
	for(int i=1;i<=n;i++)
		printf("%d ",arr[i]);
	cout<<"\n";
	return 0;
}