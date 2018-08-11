#include <iostream>
#include <unordered_map>
#include <bitset>

using namespace std;

#define gc getchar_unlocked
#define llong long long
const llong MOD = 4294967296;

unordered_map<long long int,bool> m;
bitset< MOD > bs;

void getint(int &x){
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

int main(){
	int q,s,a,b,ele;
	getint(q);
	getint(s);
	getint(a);
	getint(b);
	long long int sum=0;
	for(int i=1;i<=q;i++){
		ele=(s+1)/2;
		if(s%2 and !bs.test(ele))
			sum+=ele,bs.set(ele);
		if(s%2==0 and bs.test(ele))
			sum-=ele,bs.reset(ele);
		s=(a*s)+b;
	}
	cout<<sum<<"\n";
	return 0;
}