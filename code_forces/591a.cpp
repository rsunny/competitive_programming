#include <iostream>

using namespace std;


int main(){
	while(1){
		int L,P,Q;
		cin>>L>>P>>Q;
		double ans = P*(1.0*L/(P+Q));
		cout<<ans<<" ";
		double l,p,q;
		l=L,p=P,q=Q;
		l=(l*p)/(p+q);
		cout<<l<<"\n";
	}
	return 0;
}	