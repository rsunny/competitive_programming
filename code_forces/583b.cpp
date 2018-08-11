#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int n,b;
int a[1009];
int dp[1009];
bool vis[1009];
vector<pair<int,pair<int,int> > > v;


int doit(int x){
	if(dp[x]!=-1)
		return dp[x];
	int res=0;
	for(int i=x+1;i<=n;i++)
		if(a[i]>=a[x] and !vis[i])
			res=max(doit(i),res);
	res++;
	dp[x]=res;
	return res;
}

void print(int x){
	b=x;
	cout<<x<<" ";
	vis[x]=true;
	if(dp[x]==1)
		return ;
	int s=100000,si;
	for(int i=x+1;i<=n;i++)
		if(a[x]<=a[i] and dp[i]==dp[x]-1 and !vis[i])
			if(s>=a[i]){
				s=a[i],si=i;
				break;
			}
	print(si);
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int res,cnt=0;
	do{
		res=0;
		memset(dp,-1,sizeof dp);
		for(int i=1;i<=n;i++)
			if(!vis[i])
				res=max(res,doit(i));
	
		int s=100000,si=-1;
		for(int i=1;i<=n;i++)
			if(dp[i]==res and !vis[i])
				if(s>=a[i])
					s=a[i],si=i;
		if(si!=-1){
			print(si);
			cout<<"\n";
			v.push_back(make_pair(a[si],make_pair(si,b)));
		}
	}while(res);

	//sort(v.begin(), v.end());
	int at=v[0].second.second;
	cout<<v[0].second.first<<" "<<v[0].second.second<<"\n";
	for(int i=1;i<(int)v.size();i++){
		cout<<at<<" "<<v[i].second.first<<" "<<v[i].second.second<<" ";
		if(at>v[i].second.first){
			cout<<" -- "<<v[i].second.second<< " " <<v[i].second.first<<" -- ";
			cout<<"in1"<<" ";
			cnt++;
			if(0!=(v[i].second.second-v[i].second.first) or i!=v.size()-1){
				cout<<"in2"<<" ",
				cnt++;
			}
		}
		at=v[i].second.second;
		cout<<"\n";
	}
	cout<<at<<" ";
	cout<<cnt<<"\n";
	return 0;
}