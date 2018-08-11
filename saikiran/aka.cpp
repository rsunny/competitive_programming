#include <iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		int m,n;
		cin>>s;
		cin>>m;
		n=s.size();
		for(int i=0;i<26;i++){
			char ch='a'+i;
			for(int j=0;j<n;j++){
				if(!m)
					break;
				if(s[j]==ch)
					m--,s[j]='-';
			}
			if(!m)
				break;
		}
		for(int i=0;i<n;i++)
			if(s[i]!='-')
				cout<<s[i];
		cout<<"\n";
	}
	return 0;
}