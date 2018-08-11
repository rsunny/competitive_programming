#include <iostream>

using namespace std;

char arr[30];
bool pre[30];
string r;

int main(){
	int n,m;
	cin>>n>>m;
	string s;
	char a,b;
	cin>>s;
	for(int i=0;i<n;i++)
		pre[s[i]-(int)'a']=true;
	for(int i=0;i<26;i++){
		a=' ';
		if(pre[i])
			a=(int)'a'+i;
		r+=a;	
	}
	cout<<r<<"\n";
	for(int i=0;i<26;i++)
		arr[i]=((int)'a')+i;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		for(int j=0;j<26;j++)
			if(r[j]==a)
				r[j]=b;
			else if (r[j]==b)
				r[j]=a;
		cout<<r<<"\n";
	}
	for(int i=0;i<n;i++)
		cout<<r[s[i]-(int)'a'];
	cout<<"\n";
	return 0;
}	