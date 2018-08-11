#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <cassert>

using namespace std;

int len;
int len1,len2;
int n,m;
int res=0;
long long int pow7[10];

int check(string s){
	int i=0;
	long long int N=0;
	for(int k=len1-1;i<len1;i++,k--)
		N+=((long long int)(s[i]-'0')*pow7[k]);
	if(N>=n)
		return 0;
	N=0;
	for(int k=len2-1;i<len;i++,k--)
		N+=((long long int)(s[i]-'0')*pow7[k]);
	if(N>=m)
		return 0;
	//cout<<s<<"\n";
	return 1;
}

void reco(string s){
	if(s.size()==len){
		res+=check(s);
		return ;
	}
	int f;
	for(int i=0;i<7;i++){
		char ch='0'+i;
		f=0;
		for(int j=0;j<(int)s.size();j++)
			if(s[j]==ch){
				f=1;
				break;
			}
		if(!f)
			reco(s+ch);
	}
	return ;
}

int main(){
	pow7[0]=1;
	for(int i=1;i<10;i++)
		pow7[i]=pow7[i-1]*7;
	cin>>n>>m;
	int temp=n-1;
	while(temp){
		temp/=7;
		len1++;
	}
	temp=m-1;
	while(temp){
		temp/=7;
		len2++;
	}
	len1=max(len1,1);
	len2=max(len2,1);
	len=len1+len2;
	reco("");
	cout<<res<<"\n";
	return 0;
}

