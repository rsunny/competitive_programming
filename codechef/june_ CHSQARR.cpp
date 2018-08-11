#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <deque>

using namespace std;

int rec[1009][1009];
int row_maxn[1009][1009];
int sum[1009][1009];
int tot,maxn,maxf,n,m,q,l,b,num,res;
int cnt=0;

#define gc getchar_unlocked

void getint(int &x){
   register int c = gc();
   x = 0;
   for(;(c<48 || c>57);c = gc());
   for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}

void maxSlidingWindowRow(int row, int w) {
  deque<int> Q;
  for (int i=1;i<=w;i++) {
    while (!Q.empty() && rec[row][i] >= rec[row][Q.back()])
      Q.pop_back();
    Q.push_back(i);
  }
  for (int i=w+1;i<=m;i++) {
    row_maxn[row][i-w] = rec[row][Q.front()];
    while (!Q.empty() && rec[row][i] >= rec[row][Q.back()])
      Q.pop_back();
    while (!Q.empty() && Q.front() <= i-w)
      Q.pop_front();
    Q.push_back(i);
  }
  row_maxn[row][m-w+1] = rec[row][Q.front()];
  return ;
}

void maxSlidingWindowCol(int col, int w) {
  deque<int> Q;
  for (int i=1;i<=w;i++) {
    while (!Q.empty() && row_maxn[i][col] >= row_maxn[Q.back()][col])
      Q.pop_back();
    Q.push_back(i);
  }
  for (int i=w+1;i<=n;i++) {
    int j=col;
    tot=sum[i-w+l-1][j+b-1]-sum[i-w-1][j+b-1]-sum[i-w+l-1][j-1]+sum[i-w-1][j-1];
    tot-=((num)*row_maxn[Q.front()][col]);
    res=min(res,abs(tot));
    while (!Q.empty() && row_maxn[i][col] >= row_maxn[Q.back()][col])
      Q.pop_back();
    while (!Q.empty() && Q.front() <= i-w)
      Q.pop_front();
    Q.push_back(i);
  }
  int j=col;
  int i=n+1;
  tot=sum[i-w+l-1][j+b-1]-sum[i-w-1][j+b-1]-sum[i-w+l-1][j-1]+sum[i-w-1][j-1];
  tot-=((num)*row_maxn[Q.front()][col]);
  res=min(res,abs(tot));
  return ;
}

int main(){
	getint(n);
	getint(m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			getint(rec[i][j]);
			sum[i][j]=sum[i][j-1]+rec[i][j]+sum[i-1][j]-sum[i-1][j-1];
		}

	getint(q);
	while(q--){
		res=1e9;res+=7;
		getint(l);getint(b);
		if(l==1 and b==1){
			printf("0\n");
			continue;
		}	
		num=l*b;
		for(int i=1;i<=n;i++)
			maxSlidingWindowRow(i,b);
		for(int i=1;i<=m-b+1;i++)
			maxSlidingWindowCol(i,l);

		printf("%d\n",res);
				
	}
	return 0;
}