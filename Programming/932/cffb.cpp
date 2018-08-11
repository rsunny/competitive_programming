#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int dp[1000009];
vector<int> idx[10];

int calc(int id){
	string s;
	stringstream ss;
	ss<<id;
	ss>>s;
	int res=1;
	for(int i=0;i<(int)s.size();i++){
		if(s[i]!='0')
			res*=(s[i]-'0');
	}
	return res;
}

int l,r,k;

int findrange(){
    int tl=lower_bound(idx[k].begin(),idx[k].end(),l)-idx[k].begin();
    int tr=upper_bound(idx[k].begin(),idx[k].end(),r)-idx[k].begin();
    if(tr==(int)idx[k].size() or idx[k][tr]>r)
        tr--;
    return tr-tl+1;
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	
	for(int i=1;i<10;i++){
		dp[i]=i;
		idx[dp[i]].push_back(i);
	}

	for(int i=10;i<=1000000;i++){
		dp[i]=dp[calc(i)];
		idx[dp[i]].push_back(i);
	}

	int q;
	cin>>q;
	while(q--){
		cin>>l>>r>>k;
		cout<<findrange()<<"\n";
	}
	return 0;
}