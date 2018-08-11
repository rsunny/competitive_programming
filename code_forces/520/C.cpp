#include <iostream>

using namespace std;

#define mod 1000000009 

string s;
int n;

long long int perm[100009];
int freq[30];

int extendedEuclid(int a, int b) {
    int x = 1, y = 0;
    int xLast = 0, yLast = 1;
    int q, r, m, n;
    while(a != 0) {
        q = b / a;
        r = b % a;
        m = xLast - q * x;
        n = yLast - q * y;
        xLast = x, yLast = y;
        x = m, y = n;
        b = a, a = r;
    }
    return xLast;
}
 
int modInverse(int a, int m) {
    return (extendedEuclid(a,m) + m) % m;
}

int main(){
	cin>>n;
	cin>>s;
	perm[0]=1;
	for(int i=1;i<=n;i++){
		perm[i]=i*perm[i-1];
		perm[i]%=mod;
		freq[s[i-1]-'A']++;
	}
	long long int res=1;
	res*=perm[n];
	for(int i=0;i<=26;i++){
		res*=modInverse(perm[freq[i]],mod);
		res%=mod;
	}
	cout<<res<<"\n";
	return 0;
}