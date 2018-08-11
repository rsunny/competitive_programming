#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>

using namespace std;

int n;
vector<pair<int,pair<int,int> > >p1,p2;
map<int,int> x,y;
vector<int> xx,yy;

int main(){
	int a,b,c,n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		p1.push_back(make_pair(a,make_pair(b,i+1)));
		p2.push_back(make_pair(b,make_pair(a,i+1)));
		x[a]++,y[b]++;
	}
	sort(p1.begin(), p1.end());
	sort(p2.begin(), p2.end());
	
	vector<int> res;
	int ans=-1;

	for(int i=0;i<n;i++){
		a=p1[i].first,b=p1[i].second.first,c=p1[i].second.second;
		if(x[a]>1){
			ans=a;
			res.push_back(c);
			c=p1[i+1].second.second;
			res.push_back(c);
			break;
		}
	}
	if(res.size()){
		for(int i=0;i<n;i++){
			a=p1[i].first,b=p1[i].second.first,c=p1[i].second.second;
			if(a<ans and p1[i+1].first==ans)
				res.push_back(c);
			if(a>ans and p1[i-1].first==ans)
				res.push_back(c);
		}
		if((int)res.size()>2){
			cout<<res[0]<<" "<<res[1]<<" "<<res[2]<<"\n";
			return 0;
		}
	}

	res.clear();

	for(int i=0;i<n;i++){
		a=p2[i].first,b=p2[i].second.first,c=p2[i].second.second;
		if(y[a]>1){
			ans=a;
			res.push_back(c);
			c=p2[i+1].second.second;
			res.push_back(c);
			break;
		}
	}
	if(res.size()){
		for(int i=0;i<n;i++){
			a=p2[i].first,b=p2[i].second.first,c=p2[i].second.second;
			if(a<ans and p2[i+1].first==ans)
				res.push_back(c);
			if(a>ans and p2[i-1].first==ans)
				res.push_back(c);
		}
		if((int)res.size()>2){
			cout<<res[0]<<" "<<res[1]<<" "<<res[2]<<"\n";
			return 0;
		}
	}

	res.clear();

	for(int i=2;i<n;i++){
		long long int a1=p1[i-2].first,b1=p1[i-2].second.first,c1=p1[i-2].second.second;
		long long int a2=p1[i-1].first,b2=p1[i-1].second.first,c2=p1[i-1].second.second;
		long long int a3=p1[i].first,b3=p1[i].second.first,c3=p1[i].second.second;
		if((b3-b1)*(a2-a1)!=(b2-b1)*(a3-a1)){
			cout<<c1<<" "<<c2<<" "<<c3<<"\n";
			return 0;
		}
	}


	for(int i=2;i<n;i++){
		long long int b1=p2[i-2].first,a1=p2[i-2].second.first,c1=p2[i-2].second.second;
		long long int b2=p2[i-1].first,a2=p2[i-1].second.first,c2=p2[i-1].second.second;
		long long int b3=p2[i].first,a3=p2[i].second.first,c3=p2[i].second.second;
		if((b3-b1)*(a2-a1)!=(b2-b1)*(a3-a1)){
			cout<<c1<<" "<<c2<<" "<<c3<<"\n";
		}
	}

	return 0;
}