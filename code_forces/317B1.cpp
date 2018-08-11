#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
//#include <bits/stdc++.h>

using namespace std;
const int maxn = (3 * 1e5) + 9;

vector<pair<int,int> >s,b;
vector<pair<int,int> > rs,rb;
int n,S;

int main(int argc, char *argv[]){
	cin>>n>>S;
	char ch;
	int a,b;
	for(int i=0;i<n;i++){
		cin>>ch>>a>>b;
		if(ch=='S')
			s.push_back(make_pair(a,b));
		else
			b.push_back(make_pair(a,b));
	}
	sort(s.begin(), s.end());
	sort(b.begin(), b.end());
	
	rs.push_abck(s[0]);
	int pt=1;
	for(int i=1;i<s.size();i++){
		if(rs[pt].first==s[i].first)
			rs[pt].second+=s[i].second;
		else
			rs.push_back(s[i]),pt++;
	}

	
	return 0;
}
