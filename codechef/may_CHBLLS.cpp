#include <iostream>
 
using namespace std;
 
int res;
 
int main(){
	cout<<1<<"\n";
	cout<<1<<" "<<1<<"\n";
	cout<<1<<" "<<5<<"\n";
	cout<<flush;
	cin>>res;
	if(res!=0){
		cout<<2<<"\n";
		if(res<0){
			cout<<5<<"\n";
			cout<<flush;
			return 0;
		}
		cout<<1<<"\n";
		cout<<flush;
		return 0;
	}
	cout<<1<<"\n";
	cout<<1<<" "<<2<<"\n";
	cout<<1<<" "<<4<<"\n";
	cout<<flush;
	cin>>res;
	if(res!=0){
		cout<<2<<"\n";
		if(res<0){
			cout<<4<<"\n";
			cout<<flush;
			return 0;
		}
		cout<<2<<"\n";
		cout<<flush;
		return 0;
	}
	cout<<2<<"\n";
	cout<<3<<"\n";
	cout<<flush;
	return 0;
} 