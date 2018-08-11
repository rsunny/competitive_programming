#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long int mod=(1e9)+7;

int main(){
	int n;
	cin>>n;
	vector<int> a;
	int temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		a.push_back(temp);
	}
	sort(a.begin(), a.end());
	int idx=n-1; idx/=2;
	cout<<a[n-1-idx]-a[0]<<"\n";
	return 0;
}