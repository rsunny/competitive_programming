#include <iostream>
#include <queue>
#include <utility>
#include <map>
using namespace std;

priority_queue<int>freq;
map<int,int> vis;

int main(){
	int n;
	cin>>n;
	int a;
	for(int i=0;i<n;i++){
		cin>>a;
		freq.push(a);
	}
	long long int res=0;
	while(freq.size()){
		int ele=freq.top();
		freq.pop();
		//cout<<ele<<" ";
		if(vis[ele]){
			//cout<<"in ";
			if(ele>1)
				freq.push(ele-1);
			continue;
		}
		vis[ele]=1;
		res+=ele;
	}
	cout<<res<<"\n";
	return 0;
}