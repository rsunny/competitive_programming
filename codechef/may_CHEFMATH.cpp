#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<long long int> fib;
unordered_map<int, unordered_map<long long int, unordered_map<int,int> > >dp,vis;
long long int sum,k;

void pre(){
	fib.push_back(1);
	fib.push_back(2);
	int sz=2;
	while((fib[sz-2]+fib[sz-1])<=(int)1e9)
		fib.push_back(fib[sz-2]+fib[sz-1]), sz++;
	return ;
}

int doit(int pos, int sum, int sz){
	if(sum==0)
		return (sz==0);
	if(pos==(int)fib.size() or sz==0)
		return 0;
	if(sum>sz*fib[pos]) 
		return 0;
	int res=0;
	for(int i=0;i<=sz;i++)
		if(sum>=(i*fib[pos]))
			res+=doit(pos+1,sum-(i*fib[pos]),sz-i);
		else break;
	return res;
}

int main(){
	pre();
	sort(fib.rbegin(),fib.rend());
	int t;
	cin>>t;
	while(t--){
		cin>>sum>>k;
		cout<<doit(0,sum,k)<<"\n";
	}
	return 0;
}