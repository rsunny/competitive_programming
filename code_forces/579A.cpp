#include <iostream>

using namespace std;

int main(){
	long long int n;
	cin>>n;
	int cnt=0;
	while(n){
		if(n%2)
			cnt++;
		n/=2LL;
	}
	cout<<cnt<<"\n";
	return 0;
}