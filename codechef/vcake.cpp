#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

long long int m,k,j,r,c;
vector<long long int> v;

bool check(long long int x,long long int y,int st){
	long long int tempx=x;
	long long int tempy=y;
	for(int i=0;i<8;i++){
		for(int j=0,k=st;j<3;k++,j++){
			k%=3;
			m=v[k];
			if(!x or !y)
				return false;
			if(i&(1<<j)){
				if(m%x)
					break;
				y-=m/x;
			}
			else{
				if(m%y)
					break;
				x-=m/y;
			}
		}
		if((x==0LL) or (y==0LL))
			return true;
		x=tempx,y=tempy;
	}
	return false;
}

int main(){
	int t;
	string s;
	scanf("%d",&t);
	for(int test=1;test<=t;test++){
		s="No";
		scanf("%lld %lld",&r,&c);
		for(int i=0;i<3;i++)
			scanf("%lld",&m),v.push_back(m);
		int st=0;
		do{
			if(check(r,c,st)){
				s="Yes";
				break;
			}
			st++;
		}while(st<3);
		cout<<s<<"\n";
	}
	return 0;
}
