#include <iostream>

using namespace std;

#define mod 1000000007
#define GI ({int t;scanf("%d",&t);t;})
#define GD ({double t;scanf("%lf",&t);t;})
#define GF ({float t;scanf("%f",&t);t;})
#define GL ({long long t;scanf("%lld",&t);t;})
#define GLD ({long double t;scanf("%Lf",&t);t;})

long long int arr[100005];
long long int m;
long long int inv_mod[100005];

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
		inv_mod[i]=eff_pow(i,mod-2);

	int t,x,n;
	t = GI;
	while(t--){
		n = GI;
		x = GI;
		m = GL; m%=mod;
		for(int i=1;i<=n;i++)
			arr[i] = GL, arr[i]%=mod;
		long long int mul = 1;
		arr[x+1]=0;
		for(int i=2,j=x;j>0;i++,j--){
			arr[j]= arr[j+1] + (mul * arr[j]);
			arr[j]%=mod;
			mul*=(m-2+i); mul%=mod;
			mul*=inv_mod[i-1]; mul%=mod;
		}
		cout<<arr[1]<<"\n";
	}
	return 0;
}