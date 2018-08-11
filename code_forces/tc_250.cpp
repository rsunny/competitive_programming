#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

using namespace std;

int note[15];
bool dp[20][100][2];
int dig[]={4,7};

bool doit(int pos,int carry,int num){
	if(pos==0){
		if(note[pos]==-1){
			if(num!=1)
				return (carry!=0 and carry<=9);
				
			if(num!=2)
				return (carry+4<=9 or carry+7<=9);
				
			return (carry+8<=9);
		}
		if(num!=1)
			return (carry==note[0]);
		if(num!=2)
			return (carry+4==note[0] or carry+7==note[0]);
		if(num==0)
			return (carry+8==note[0]);
	}
	if(dp[pos][carry][num])
		return dp[pos][carry][num];
	if(note[pos]!=-1){
		if(num!=1){
			if(carry%10==note[pos])
				dp[pos][carry][num]|=doit(pos-1,carry/10,2);
		}
		if(num!=2){
			if((carry+4)%10==note[pos])
				dp[pos][carry][num]|=doit(pos-1,(carry+4)/10,1);
			if((carry+7)%10==note[pos])
				dp[pos][carry][num]|=doit(pos-1,(carry+7)/10,1);
		}
		if(num==0){
			for(int i=0;i<2;i++){
				for(int j=0;j<2;j++){
					if((dig[i]+dig[j]+carry)%10==note[pos])
						dp[pos][carry][num]|=doit(pos-1,dig[i]+dig[j]+carry/10,0);
				}
			}
		}
		return dp[pos][carry][num];
	}
	if(num!=1){
		dp[pos][carry][num]|=doit(pos-1,carry/10,2);
	}
	if(num!=2){
		dp[pos][carry][num]|=doit(pos-1,(carry+4)/10,1);
		dp[pos][carry][num]|=doit(pos-1,(carry+7)/10,1);
	}
	if(num==0){
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				dp[pos][carry][num]|=doit(pos-1,dig[i]+dig[j]+carry/10,0);
			}
		}
	}
	return dp[pos][carry][num];	
}

class LuckySum {
public:
	long long construct(string no) {
		for(int i=0;i<(int)no.size();i++){
			if(no[i]=='?')
				note[i]=-1;
			else note[i]=no[i]-'0';
		}
		memset(dp,false,sizeof dp);
		int sz=no.size();
		if(!doit(sz-1,0,0))
			return -1;
		
		return 2LL;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!