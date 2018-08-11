#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

int main(){
	int n;
	n=10000;
	cout<<n<<"\n";
	for(int i=0;i<n;i++){
		int ele=abs(rand()%(int)1e9);ele++;
		cout<<ele<<" ";
	}
	cout<<"\n";
	int q,c,r,f;
	q=10000;
	cout<<q<<"\n";
	while(q--){
		c=abs(rand()%4);c++;
		r=abs(rand()%n);r++;
		while (r > n) r--; 
		if(c==3)
			r=83161;
		c%=2;c++;
		cout<<c<<" "<<r;
		if(c!=2){
			f=abs(rand()%(int)1e9);f++;
			cout<<" "<<f;
		}
		cout<<"\n";
	}
	return 0;
}
