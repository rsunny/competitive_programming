#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
 
#pragma comment(linker, "/STACK:16777216")
 
using namespace std;
 
vector<long long int> solution;

long long int  ggabs(long long int  n){
	return n<0 ? -n : n;
}

bool rec(long long int  n,long long int  s){
	if(s>n*(n-1)/2) return false;
	if(s<-n*(n-1)/2) return false;
	if(n/2%2 != ggabs(s)%2) return false;

	if(n==1) return true;

	if(s>=0){
		rec(n-1,s-(n-1));
		cout<<n<<" "<<s<<" "<<"1\n";
		solution.push_back(+1);
	}
	else{
		rec(n-1,s+(n-1));
		cout<<n<<" "<<s<<" "<<"-1\n";
		solution.push_back(-1);
	}

	return true;
}

void solve(long long int  n, long long int  s){
	solution.clear();
	if(rec(n,s)){
		long long int  sum = 0;
		cout<<sum<<endl;
		for(int i=solution.size()-1; i>=0; i--){
			sum += solution[i];
			cout<<sum<<endl;
		}
	}
	else
		cout<<"No"<<endl;

	return ;
}

 
int main(){
    int t;
	cin>>t;
	while(t--){
		long long int  n,s;
		cin>>n>>s;
		solve(n,s);
	}
    return 0;
}