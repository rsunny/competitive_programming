#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <cassert>

using namespace std;

#define MAXN 1000000
#define mod 1000000007

int pow10[9];
int arr[1000009];
int bit[1000009];
stringstream ss;
string s;

void amazingness(int a){
	ss.clear(); ss<<a; ss>>s;
	int b=a%pow10[(int)s.size()-1];
	arr[a]=arr[b];
	bit[a]=bit[b];
	int d=0;
    for(int i=0; i<s.size();i++){
    	d=d^(s[i]-'0');
        if(!(bit[a] & (1<<d)) ){
        	bit[a]|=(1<<d);
        	arr[a]+=d;
        }  
   }
   return ;
}

int main(){
	pow10[0]=1;
	for(int i=1;i<=7;i++)
		pow10[i]=10*pow10[i-1];
	for(int i=1;i<=MAXN;i++)
		amazingness(i);
	for(int i=1;i<=MAXN;i++)
		arr[i]+=arr[i-1];
	int t;
	int l,r;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&l,&r);
		printf("%d\n",arr[r]-arr[l-1]);
	}
	return 0;
}
