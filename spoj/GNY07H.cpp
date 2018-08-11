#include <iostream>
#include <string.h>

using namespace std;

int dp[105][1<<4];
int nm,tm;

int doit(int pos,int mask){
	if(pos==0)
		return (mask==15);
	if(dp[pos][mask]!=-1)
		return dp[pos][mask];
	int res=0;
	int vm=0;
	for(int i=0;i<(1<<4);i++){
		nm=15;
		tm=mask;
		for(int j=0;j<4;j++){
			if((tm&(1<<j)) and !(i&(1<<j)))
				tm&=~(1<<j),nm&=~(1<<j);
			if((tm&(1<<j)) and (i&(1<<j))){
				if(j<3 and (tm&(1<<(j+1))))
					tm&=~(1<<j),tm&=~(1<<(j+1));
				else
					goto here;
			}
		}
		if(!(vm&(1<<nm))){
			vm|=(1<<nm);
			res+=doit(pos-1,nm);
		}
		here: ;
	}
	dp[pos][mask]=res;
	return res;
}

int main(){
	memset(dp,-1,sizeof dp);
	int t,p;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>p;
		cout<<i<<" "<<doit(p,15)<<"\n";
	}
	return 0;
}