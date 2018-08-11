#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

long long int mod=(1e9)+7;

int main(){
	int n,k;
	cin>>n>>k;
	long long int res=1;
	vector<int> a,b;
	int temp;
	int blocks=n/k;
	for(int i=0;i<blocks;i++){
		cin>>temp;
		a.push_back(temp);
	}
	for(int i=0;i<blocks;i++){
		cin>>temp;
		b.push_back(temp);
	}
	int maxk=1;
	for(int i=1;i<k;i++)
		maxk*=10;
	for(int i=0;i<blocks;i++){
		// for(int j=0;;j++){
		// 	stringstream ss;
		// 	string s;
		// 	ss<<(j*a[i]);
		// 	ss>>s;
		// 	if(s.size()>k)
		// 		break;
		// 	if(s.size()<k and b[i]==0)
		// 		continue;
		// 	if(s.size()==k and (s[0]-'0')==b[i])
		// 		continue;
		// 	cnt++;
		// }
		long long int cnt=0;
		int mul=b[i]*maxk;mul--;
		int cnt1=(mul/a[i])+1;
		cout<<mul<<" "<<cnt1<<"\n";
		mul=(b[i]+1)*maxk;mul--;
		int cnt2=(mul/a[i])+1;
		cout<<mul<<" "<<cnt2<<"\n";
		mul=(10*maxk)-1;
		int cnt3=(mul/a[i])+1;
		cout<<mul<<" "<<cnt3<<"\n";
		if(b[i]==0)
			cnt=cnt3-cnt2;
		else if(b[i]==9)
			cnt=cnt3-cnt1;
		else
			cnt=cnt3+cnt1-cnt2;
		cout<<cnt<<"\n";
		res*=(long long int)cnt;
		res%=mod;
	}
	cout<<res<<"\n";
	return 0;
}