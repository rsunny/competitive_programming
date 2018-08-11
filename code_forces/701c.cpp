#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <map>

using namespace std;

int freq[105];
int cnt=1;
map<char,int> mp;

int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		if(!mp[s[i]])
			mp[s[i]]=cnt,cnt++;
		// cout<<s[i]<<" "<<mp[s[i]]<<"\n";
	}
	cnt--;
	int ans=n;
	for(int i=0,j=0;i<n;i++){
		for(;j<=n;j++){
			
			int sum=0;
			for(int k=1;k<=cnt;k++){
				// cout<<freq[k]<<" ";
				if(freq[k]>0)
					sum++;
			}
			// cout<<" -- ";
			// cout<<i<<" "<<j<<" "<<sum<<" "<<cnt<<"\n";
			if(sum==cnt){
				// cout<<i<<" "<<j-1<<"\n";
				ans=min(ans,j-i);
				break;
			}
			if(j<n)
				freq[mp[s[j]]]++;
		}
		freq[mp[s[i]]]--;
	}
	cout<<ans<<"\n";
	return 0;
}
