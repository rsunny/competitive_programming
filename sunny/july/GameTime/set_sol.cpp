#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define FOR(i,a,n) for(int i=(a);i<(n);++i)
#define FORE(i,a,n) for(int i=(a);i<=(n);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REPE(i,n) for(int i=0;i<=(n);++i)

const int MAXN=100;

int n;
int MOD=1000000007;
int pw(int x,int n) { int ret=1; while(true) { if(n&1) ret=(ll)ret*x%MOD; if((n>>=1)==0) return ret; x=(ll)x*x%MOD; } }

int dp[MAXN+1][MAXN+1]; // dp[i][j] = #ways to make a length i sequence with j unique top-level items
int ways[MAXN+1]; // ways[i] = #valid question sets for i items
int nq[MAXN+1]; // nq[i] = #questions for i items
int pnq[MAXN+1]; // pnq[i] = 2^nq[i]

void inc(int &a,int x) { if((a+=x)>=MOD) a-=MOD; }
void inc(int &a,int x,int y) { a=(a+(ll)x*y)%MOD; }
void dec(int &a,int x) { if((a-=x)<0) a+=MOD; }
void dec(int &a,int x,int y) { dec(a,(ll)x*y%MOD); }


/*
 * Complete the function below.
 */
int countQue(int N){
    n=N;
    memset(dp,0,sizeof(dp));
    memset(ways,0,sizeof(ways));
    REPE(i,n) nq[i]=i*(i+1)/2;
    REPE(i,n) pnq[i]=pw(2,nq[i]);

    dp[0][0]=1;
    REP(i,n) REPE(j,i) {
        inc(dp[i+1][j+1],dp[i][j]);
        FORE(ni,i+2,n) {
            inc(dp[ni][j+1],dp[i][j],pnq[ni-i-2]);
        }
    }
    //REPE(i,n) REPE(j,i) printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
    
    REPE(i,n) {
        ways[i]=pnq[i];
        REP(j,i) dec(ways[i],dp[i][j],ways[j]);
    }
    return ways[n];
}

int main(){
    int res;
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    res = countQue(n);
    cout << res << endl;

    return 0;
}
