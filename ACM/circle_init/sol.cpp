#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int n;//,k;
bool vis[10005][10005];
long long int ans[10005];
long long int res;

int bfs(){
	for(int i=0;i<n;i++)
		ans[i]=1e9;
	queue<int> pos,steps;
	pos.push(0);
	steps.push(0);
	vis[0][0]=true;
	while(pos.size()){
		int p=pos.front(), s=steps.front();
		ans[p]=min(ans[p],(long long int)s);
		pos.pop(); steps.pop();
		if(!vis[(p+s+1)%n][(s+1)%n]){
			//cout<<"  --> "<<(p+s+1)%n<<" "<<(s+1)<<"\n";
			vis[(p+s+1)%n][(s+1)%n]=true;
			pos.push((p+s+1)%n);
			steps.push(s+1);
		}
		if(!vis[(p-s-1+n)%n][(s+1)%n]){
			//cout<<"  --> "<<(p-s-1+n)%n<<" "<<(s+1)<<"\n";
			vis[(p-s-1+n)%n][(s+1)%n]=true;
			pos.push((p-s-1+n)%n);
			steps.push(s+1);
		}
	}
	long long int maxi=0;
	for(int i=0;i<n;i++){
		cout<<i<<" "<<ans[i]<<"\n";
		maxi=max(maxi,ans[i]);
	}
	cout<<maxi<<"\n";
	return -1;
}

int main(){
	cin>>n;
	res=bfs();
	return 0;
}