#include <iostream>
#include <vector>
#include <map>

using namespace std;

int max_n;
map<int,long long int> sz;

void dfs(vector<int> v, int num){
	if(num==max_n){
		sz[(int)v.size()]++;
		return;
	}
	dfs(v,num+1);
	for(int i=0;i<(int)v.size();i++)
		if(__gcd(v[i],num)!=1)
			return ;
	v.push_back(num);
	dfs(v,num+1);
	return ;
}

int main(){
	int i=25;
	max_n=i+1;
	sz.clear();
	vector<int> v;
	dfs(v,2);
	map<int, long long int> :: iterator it;
	cout<<max_n-1<<"\n";
	for(it=sz.begin();it!=sz.end();it++)
		cout<<it->first<<" "<<it->second<<"\n";
	return 0;
}