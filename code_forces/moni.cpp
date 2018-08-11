#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

int main(){
	string error = "Error in input line";
	cout<<"Name : Monica Marisetty\n";
	cout<<"UIN : \n";
	string s;
	while(getline(cin,s)){
		string arr[5];
		int cnt=0;
		for(int i=0;i<s.size();i++){
			if(cnt==4){
				cout<<error<<"\n";
				goto nxt;
			}
			if(s[i]=='.')
				cnt++;
			else{
				arr[cnt]+=s[i];
			}
		}
		for(int i=0;i<3;i++){
			if(arr[i].size()==0){
				cout<<error<<"\n";
				goto nxt;
			}
			for(int j=0;j<arr[i].size();j++){
				if(arr[i][j]<'0' or arr[i][j]>'9'){
					cout<<error<<"\n";
					goto nxt;
				}
			}
		}
		s=arr[3];
		arr[3]=arr[4]="";
		cnt=3;
		for(int i=0;i<s.size();i++){
			if(s[i]==':')
				cnt++;
			else{
				arr[cnt]+=s[i];
			}
		}
		for(int i=3;i<5;i++){
			if(arr[i].size()==0){
				cout<<error<<"\n";
				goto nxt;
			}
			for(int j=0;j<arr[i].size();j++){
				if(arr[i][j]<'0' or arr[i][j]>'9'){
					cout<<error<<"\n";
					goto nxt;
				}
			}
		}
		cout<<"Address: "<<arr[0]<<"."<<arr[1]<<"."<<arr[2]<<"."<<arr[3]<<", Port: "<<arr[4]<<"\n";
		nxt : continue;
	}
	return 0;
}
