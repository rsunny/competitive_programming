#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

long long int n,temp;
int digit;

int main(){
	int t,num=200,temp,i;
	cin>>t;
	while(t--){
		printf("Case #%d: ",num++);
		digit=0;
		//cin>>n;
		n=t+1;
		for(i=1;i<=n;i++){
			temp=i; temp*=n;
			cout<<i<<" "<<temp<<"\n";
			while(temp){
				digit|=(1<<(temp%10LL));
				temp/=10LL;
			}
			if((digit+1)==(1<<10))
				break;
		}	
		if((digit+1)==(1<<10))
			cout<<(n*i)<<"\n";
		else
			cout<<"INSOMNIA\n";
	}
	return 0;
}