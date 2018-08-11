#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int n;
int digit;

int main(){
	int t,num=1,temp,i;
	cin>>t;
	while(t--){
		printf("Case #%d: ",num++);
		digit=0;
		cin>>n;
		if(!n){
			cout<<"INSOMNIA\n";
			continue;
		}
		for(i=1;;i++){
			temp=n*i;
			while(temp){
				digit|=(1<<(temp%10));
				temp/=10;
			}
			if((digit+1)==(1<<10))
				break;
		}	
		cout<<n*i<<"\n";
	}
	return 0;
}