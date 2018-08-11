#include <iostream> 
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

vector<pair<int,int> >v;
vector<pair<int,int> >fin;

int main(){
	int n,k,ele;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		scanf("%d",&ele);
		v.push_back(make_pair(10-(ele%10),ele));
	}
	sort(v.begin(), v.end());
	int res=0; 
	int need;
	for(int i=0;i<n;i++){
		//cout<<v[i].first<<" "<<v[i].second<<" ";
		need=v[i].first;
		if(k>=need)
			k-=need,v[i].second+=need;
		//cout<<v[i].second<<"\n";
		fin.push_back(make_pair(v[i].second%10==0,v[i].second));
	}
	sort(fin.rbegin(), fin.rend());

	for(int i=0;i<n;i++){
		ele=fin[i].second;
		need=100-ele;need=min(need,k);
		k-=need,ele+=need;
		//cout<<ele<<" "<<res<<"\n";
		res+=(ele/10);
	}
	cout<<res<<"\n";
	return 0;
}