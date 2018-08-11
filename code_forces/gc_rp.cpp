#include <iostream>
#include <stdio.h>

using namespace std;

int n,m;

int main(){
	int t,num=1;
	int res;
	string s1,s2;
	cin>>t;
	while(t--){
		cin>>s1;
		s2.clear(), res=0;	n=s1.size();
		s2+=s1[0]; m=1;
		for(int i=1;i<n;i++){
			//cout<<s1[i]<<" "<<s2[m-1]<<" ";
			if(s1[i]!=s2[m-1])
				s2+=s1[i],m++;//,cout<<s1[i]<<" "<<s2[m-1]<<" ";
			//cout<<"\n";
		}
		for(int i=0;i<m;i++){
			if(s2[i]=='-')
				res++,res+=(i!=0);
		}
		//cout<<s1<<" "<<s2<<" ";
		printf("Case #%d: ",num++);
		cout<<res<<"\n";
	}
	return 0;
}