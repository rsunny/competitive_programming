#include <iostream>
#include <priority_queue>
#include <utility>

using namespace std;

int arr[30];
priority_queue<pair<int,int> > q;

int main(){
	int test;
	cin>>test;
	for(int t=1;t<=test;t++){
		int n;
		cin>>n;
		int tot=0;
		for(int i=0;i<n;i++){
			cin>>arr[i];
			tot+=arr[i];
			q.push(make_pair(arr[i],i));
		}
		while(q.size()){
			pair<int,int> a,b;
			a = q.top(); q.pop();

		}
	}
	return 0;
}