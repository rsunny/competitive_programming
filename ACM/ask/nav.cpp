#include <iostream>

using namespace std;

int main(){
	int n,arr[8],temp,j=0,count=0;
	cin>>n;
	for(int i=0;i<7;i++){
		cin>>temp;
		arr[i]=temp;
	}
	while(n>0){
		n-=arr[j];
		if(n>0)
			j++,j%=7;
	}
	cout<<j+1<<endl;
	return 0;
}