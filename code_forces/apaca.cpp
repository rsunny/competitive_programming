#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define MOD 1000000007
#define ll long long
using namespace std;

string s;
ll dp[1001][26];
int rec(int index, int prev){
	if(index==s.size())
		return 1;
	if(dp[index][prev]!=-1)
		return dp[index][prev];
	dp[index][prev]=0;
	dp[index][prev] += rec(index+1, s[index]-'a');
	dp[index][prev]%=MOD;
	if(index-1>=0 and s[index-1]!=s[index])
		dp[index][prev] += rec(index+1, s[index-1]-'a');
	dp[index][prev]%=MOD;
	if(index+1<s.size() and s[index+1]!=s[index])
		dp[index][prev] += rec(index+1, s[index+1]-'a');
	dp[index][prev]%=MOD;
	return dp[index][prev]%MOD;
}
int main(){
	int t;
	cin>>t;
	int cnt=0;
	while(t--){
		cin>>s;
		cnt++;
		// memset(dp,-1,sizeof dp);
		// ll ans =rec(0,0)%MOD;
		ll ans =1;
		for(int i=0;i<s.size();i++){
			set<char>sa;
			if(i-1>=0)
				sa.insert(s[i-1]);
			sa.insert(s[i]);
			if(i+1<s.size())
				sa.insert(s[i+1]);
			ans = (ans*sa.size())%MOD;

		}
		cout<<"Case #"<<cnt<<": "<<ans<<endl;
	}
	return 0;
}