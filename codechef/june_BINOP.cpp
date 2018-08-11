#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
	int t;
	string s1,s2;
	int diff[2];
	int cnt[2];
	scanf("%d",&t);
	for(int test=1;test<=t;test++){
		cin>>s1>>s2;
		diff[1]=diff[0]=0;
		cnt[1]=cnt[0]=0;
		for(int i=0;i<(int)s1.size();i++){
			if(s1[i]!=s2[i])
				diff[s1[i]-'0']++;
			cnt[s1[i]-'0']++;
		}
		if(!cnt[1] or !cnt[0])
			cout<<"Unlucky Chef\n";
		else
			cout<<"Lucky Chef\n"<<max(diff[1],diff[0])<<"\n";
	}
	return 0;
}
