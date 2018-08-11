#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
	long long int num;
	for(int i=0;i<=100;i++){
		cout<<"{";
		if(i>=2){
			cin>>num;
			for(int j=0;j<26;j++){
				cin>>num;
				if(j)
					cout<<",";
				cout<<num;
			}
		}
		else
			for(int j=0;j<26;j++){
				cout<<0;
				if(j)
					cout<<",";
			}
		cout<<"},\n";
	}
	return 0;
}