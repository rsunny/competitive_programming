#include <iostream>
#include <string.h>

using namespace std;

int dp[5005][5005];
int n;
string s;
int mod = (1e9) +7;

int doit(int pos, int len){
	cout<<pos<<" "<<len<<"\n";
	if(pos+len>=n or s[pos]=='0')
		return 0;
	if(dp[pos][len]!=-1)
		return dp[pos][len];
	int res=1;
	string s1,s2;
	for(int i=pos-len;i<len;i++){
		s1+=s[i];
	}
	for(int j=pos,k=0;k<len;k++,j++){
		if(j>=n){
			return 0;
		}
		s2+=s[j];
	}
	cout<<"s-> "<<s1<<" "<<s2<<"\n";
	int f=1;
	if(s1<s2)
		f=0;
	for(int i=pos+len+f;i<n;i++)
		res+=doit(i,i-pos),res%=mod,cout<<pos<<" "<<len<<" "<<i<<" "<<i-pos<<"\n";
	return res;
}

int main(){
	memset(dp,-1,sizeof dp);
	cin>>n;
	cin>>s;
	int res=0;
	string s1;
	for(int i=0;i<n;i++){
		res+=doit(i+1,i+1);
	}
	cout<<res<<"\n";
	return 0;
}