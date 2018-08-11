#include <iostream>
#include <set>

using namespace std;

set<int> s[55];

int main(){
	int n,ele;
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			cin>>ele;
			if(ele)
				s[i].insert(ele);
		}
	int res=n-1;
	for(int i=1;i<=n;i++){
		if((int)s[i].size()==res){
			cout<<n<<" ";
			res++;
		}
		else
			cout<<s[i].size()<<" ";
	}	
	cout<<"\n";
	return 0;
}