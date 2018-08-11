#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;

int arr[5005];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	for(int i=1;i<=n;i++){
		int a = i;
		int b = arr[a];
		int c = arr[b];
		if(arr[c]==a){
			cout<<"YES\n";
			return 0;
		}
	}
	cout<<"NO\n";
	return 0;
}
