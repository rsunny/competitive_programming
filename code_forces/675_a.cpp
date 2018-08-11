#include <iostream>

using namespace std;

int main(){
	int a,b,c;
	cin>>a>>b>>c;

	if(!c or ((b-a)%c==0) and ((b>0 and c>0) or (b<0 and c<0)))
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}