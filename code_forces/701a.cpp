#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <map>

using namespace std;

int main(){
	int n=100000;
	cout<<n<<"\n";
	for(int i=0;i<n-1;i++){
		char ch='A'+(i)%26;
		cout<<ch;
	}
	cout<<"a"<<"\n";
	return 0;
}
