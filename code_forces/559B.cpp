#include <iostream>

using namespace std;

string reco(string s1){
	int len=s1.size();
	if(len%2==1)
		return s1;
	string a1,a2,b1,b2;
	int mid=len/2;
	for(int i=0;i<mid;i++)
		a1+=s1[i];
	for(int i=mid;i<(int)s1.size();i++)
		a2+=s1[i];
	b1=reco(a1);
	b2=reco(a2);
	if(b1<b2)
		return b1+b2;
	return b2+b1;
}

int main(){
	string s1,s2;
	cin>>s1>>s2;
	if(reco(s1)==reco(s2))
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;	
}