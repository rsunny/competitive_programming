#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> q;

int main(int argc, char const *argv[])
{
	/* code */
	int n,a;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		q.push_back(a);
	}
	sort(q.begin(),q.end());
	long long int sum=q[0];
	int res=1;
	for(int i=1;i<n;i++){
		//cout<<sum<<" "<<q[i]<<"\n";
		if(sum<=q[i])
			res++,sum+=q[i];
	}
	cout<<res<<"\n";
	return 0;
}