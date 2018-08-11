#include <iostream>
#include <vector>
#include <numeric>
#include <string.h>

using namespace std;

int main(){
	int t,n,temp=0,test=0,sum=0,j=1,chk,c=0;
	vector <int> myv(10);
	cin>>t;
	c=t;
	while(t--){
		cin>>n;
		temp=n;
		if(n==0){
			cout<<"Case #"<<c-t<<": "<<"INSOMNIA\n";
		}
		else{
			while(temp>0){
			sum=0;
			//cout<<"Temp0:"<<temp<<endl;
			 test=temp%10;
			 myv[test]=1;
			 //cout<<"test:"<<test<<endl;
			 temp=temp/10;
			 //cout<<"Temp1:"<<temp<<endl;
			 for(int i=0;i<10;i++){
			 	sum+=myv[i];
			 }	
			 //cout<<"sum:"<<sum<<endl;
			 if(sum==10){
			 	cout<<"Case #"<<c-t<<": "<<chk<<endl;
			 	j=1;
			 	for(int i=0;i<10;i++){
			 		myv[i]=0;
			 	}
			 	break;
			 }
			 else if(sum<10&&temp<=0){
			 	++j;
			 	temp=j*n;
			 	chk=temp;
			 	
			 //	cout<<"J:"<<j<<endl;
			 }
			 
			}
		}
		
	}
	return 0;
}
