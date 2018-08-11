#include <iostream>
#include <vector>

using namespace std;

vector<int> v1,v2;

void print(vector<int> v){
	for(int i=0;i<(int)v.size();i++)
		cout<<v[i]<<" ";
	cout<<"\n";
	return ;
}

int med(int a,int b,int c){
	vector<int> v;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	sort(v.begin(), v.end());
	return v[1];
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		v1.push_back(temp);
	}
	

	while(1){
		v2.push_back(v1[0]);
		for(int i=1;i<n-1;i++)
			v2.push_back(med(v1[i-1],v1[i],v1[i+1]));
		v2.push_back(v1[n-1]);
		if(v1==v2)
			break;
		v1=v2;
		v2.clear();
		print(v1);
	}
	return 0;
}	