#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	string s;
	vector<string> v;
	for(int i=0;i<n;i++){
		cin>>s;
		map<char,bool> mp;
		for(int i=0;i<s.size();i++)
			mp[s[i]]=true;
		if((int)mp.size()<=2)
			v.push_back(s);
	}
	int res=0;
	for(int i=0;i<26;i++){
		for(int j=0;j<26;j++){
			int r=0;
			for(int k=0;k<(int)v.size();k++){
				bool flag=false;
				for(int l=0;l<(int)v[k].size();l++){
					if((v[k][l]-'a')!=i and (v[k][l]-'a')!=j){
						flag=1;
					}
				}
				if(!flag)
					r+=v[k].size();
			}
			res=max(res,r);
		}
	}
	cout<<res<<"\n";
	return 0;
}