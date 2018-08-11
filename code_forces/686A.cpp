#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[109];
vector<int> v;

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>arr[i],v.push_back(arr[i]);
	sort(v.begin(), v.end());
	for(int i=1;i<=n;i++){
		int j=i;
		for(;j<=n;j++)
			if(arr[j]==v[i-1])
				break;
		for(;j>i;j--){
			cout<<j-1<<" "<<j<<"\n";
			swap(arr[j],arr[j-1]);
		}
	}
	return 0;
}

