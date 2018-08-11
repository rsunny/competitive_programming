#include <iostream>
 
using namespace std;
 
int res;
 
int main(){
	int t;
	cin>>t;
	while(t--){
		res=0;
		int a,l,divi=200;
		string s;
		cin>>a>>s;
		if(s=="NON_INDIAN")
			divi=400;
		for(int i=0;i<a;i++){
			cin>>s;
			if(s=="CONTEST_WON")
				cin>>l,res+=300+max(20-l,0);
			else if(s=="TOP_CONTRIBUTOR")
				res+=300;
			else if(s=="BUG_FOUND")
				cin>>l,res+=l;
			else	res+=50;
		}
		cout<<res/divi<<"\n";
	}
	return 0;
} 