#include <iostream>
#include <vector>

using namespace std;

vector<int> v1,v2;

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		v1.push_back(temp);
	}
	
	int s=0,e=0;
	int res=0;

	for(int i=0;i<n;i++){
		if(i==0 or (i>0 and v1[i]!=v1[i-1])){
			v2.push_back(v1[i]);
			e=i;
			continue;
		}

		res=max(res,((int)v2.size()+1)/2);

		for(int j=s;j<=(s+e)/2;j++)
			v1[j]=v2[0];
		for(int j=(s+e)/2+1;j<=e;j++)
			v1[j]=v2[(int)v2.size()-1];

		v2.clear();
		v2.push_back(v1[i]);
		s=e=i;
	}

	res=max(res,((int)v2.size()+1)/2);

	for(int j=s;j<=(s+e)/2;j++)
		v1[j]=v2[0];
	for(int j=(s+e)/2+1;j<=e;j++)
		v1[j]=v2[(int)v2.size()-1];

	cout<<res-1<<"\n";
	for(int i=0;i<n;i++)
		cout<<v1[i]<<" ";

	return 0;
}	