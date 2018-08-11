#include <iostream>

using namespace std;

int main(){
	int n;
	n=10;
	for(int i=0;i<n;i++){
		cout<<abs(rand()%(int)1000)+1<<" ";
	}
	cout<<"\n";
	return 0;
}