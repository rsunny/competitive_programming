#include <iostream>

using namespace std;

long long int a,b,c,d,e;
long long int mod = (1e9) + 7;

long long eff_pow(int a, int b){
    long long x=1,y=a; 
    while(b > 0){
        if(b%2 == 1){
            x=(x*y);
            if(x>mod) x%=mod;
        }
        y = (y*y);
        if(y>mod) y%=mod; 
        b /= 2;
    }
    return x;
}

int main(){
	cin>>a>>b>>c>>d>>e;
	long long int res = a*b; res%=mod;
	res*=c; res%=mod;
	res*=eff_pow(d,mod-2); res%=mod;
	res*=eff_pow(e,mod-2); res%=mod;
	cout<<b<<"\n";
	return 0;	
}