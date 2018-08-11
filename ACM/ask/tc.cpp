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

using namespace std;

int len,n;
string s;

int lcs( string X, string Y, int m, int n )
{
   int L[m+1][n+1];
   int i, j;
  
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
  
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
  
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
    
   return L[m][n];
}

int reco(string t,int open,int close){
	if(t.size()==n)
		return (open==close and s!=t)?lcs(s,t,n,n):0;
	int res=0;
	if(open>=close)
		res=max(reco(t+"(",open+1,close),reco(t+")",open,close+1)); 
	else
		res=reco(t+")",open,close+1);
	return res; 
}

int reco1(string t,int open,int close){
	if(t.size()==n){
		if(open==close and lcs(s,t,n,n)==len){
			cout<<t<<"\n";return (s!=t);
		}
		else
			return 0;
	}
	int res=0;
	if(open>=close)
		res=reco1(t+"(",open+1,close)+reco1(t+")",open,close+1); 
	else
		res=reco1(t+")",open,close+1);
	return res; 
}


	int yetanother(string S) {
		s=S; n=s.size();
		len=reco("",0,0);
		cout<<n<<" "<<len<<"\n";
		return reco1("",0,0);
	}

int main(){
	string s;
	//cin>>s;
	//yetanother(s);
	for(int i=0;i<25;i++)
		cout<<"(";
	for(int i=0;i<25;i++)
		cout<<")";
	cout<<"\n";
	return 0;
}