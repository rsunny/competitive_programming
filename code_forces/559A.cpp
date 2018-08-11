#include <iostream>

using namespace std;

int sides[6];

int main(){
	int res=0;
	for(int i=0;i<6;i++)
		cin>>sides[i];
	int cnt=6;
	while(cnt>2){
		int temp=0;
		cnt=0;
		for(int i=0;i<6;i++){
			cout<<sides[i]<<" ";
			if(sides[i]==0)
				continue;
			cnt++;
			temp+=sides[i]+sides[i]-1;
			sides[i]--;
		}
		cout<<"\n";
		res+=temp;
	}
	cout<<res<<"\n";
	return 0;	
}