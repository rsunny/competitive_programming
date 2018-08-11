#include <iostream>

using namespace std;

int arr[100009];

int main(){
	int n;
	cin>>n;
	arr[1]=1;
	int p=2;
	for(int i=2;i<=n;i++){
		arr[p]=1;
		for(int j=p;j>=1;j--){
			if(arr[p]==arr[p-1])
				arr[p-1]++,p--;
			else 
				break;
		}
		p++;
	}
	for(int i=1;i<p;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
	return 0;
}