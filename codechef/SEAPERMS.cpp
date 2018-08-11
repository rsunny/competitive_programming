#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

set<int> arr;
vector<int> a;
long long int mod = 1000000007;
unordered_map<long long int,int> freq,nxt,bidx;
long long int inv_mod[100009];
long long int sz=1000000000;

void update(long long int i,int val){
    while(i<=sz)
        bidx[i]+=val,    i+= i&-i;
}

int read(long long int i){
    int ret=0;
    while(i>0)
        ret+=bidx[i],    i-= i&-i;
    return ret;
}

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
	for(int i=1;i<100009;i++)
		inv_mod[i]=eff_pow(i,(int)mod-2);

	int n,ele,d,val;
	int m,p,idx;
	long long int ans=1;
	set<int> :: iterator it;
	scanf("%d %d",&n,&d);
	for(int i=0;i<n;i++){
		scanf("%d",&ele);
		a.push_back(ele);
		arr.insert(ele);
		update(ele,1);
	}
	for(int i=n-1;i>=0;i--){
		idx = read(a[i]+d-1)-read(a[i])+1;
		if(!freq[a[i]])
			nxt[a[i]]=idx;
		freq[a[i]]++;
		ans*=(idx+freq[a[i]]-1);
		ans%=mod;
	}
	scanf("%d",&m);
	while(m--){
		scanf("%d %d",&p,&ele); p--;
		it = arr.find(a[p]);
		int flag=1;
		val=*it;
		while((val+d)>a[p]){
			val=(*it);
			if(flag){
				flag=0;
				ans*=inv_mod[nxt[val]+freq[val]-1]; ans%=mod;
				freq[val]--;
			}
			else{
				ans*=inv_mod[nxt[val]+freq[val]-1]; ans%=mod;
				nxt[val]--;
				ans*=nxt[val]; ans%=mod;
			}
			if(it==arr.begin())
				break;
			it--;
			val=(*it);
		}
		
		if(!freq[a[p]])
			arr.erase(arr.find(a[p]));
		update(a[p],-1);
		arr.insert(ele);
		update(ele,1);
		a[p]=ele; flag=1;

		idx = read(ele+d-1)-read(ele)+1;
		if(!freq[ele])
			nxt[ele]=idx;
		freq[ele]++;

		it = arr.find(a[p]);
		val=*it;
		while((val+d)>a[p]){
			val=(*it);
			if(flag){
				flag=0;
				ans*=(nxt[val]+freq[val]-1); ans%=mod;
			}
			else{
				ans*=inv_mod[nxt[val]]; ans%=mod;
				nxt[val]++;
				ans*=(nxt[val]+freq[val]-1); ans%=mod;
			}
			if(it==arr.begin())
				break;
			it--;
			val=(*it);
		}
		printf("%lld\n",ans);
	}
	return 0;
}