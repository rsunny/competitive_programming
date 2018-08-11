#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <utility>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <stack>

#define ll long long
#define pb push_back
#define mp make_pair
#define fir first
#define sec second
#define IN1(x) scanf("%d", &x)
#define IN2(x, y) scanf("%d%d", &x, &y)
#define IN3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define STR(x) cin>>x
#define OUT(x) printf("%d\n", x);
#define OUT1(x,y) printf("Case %d: %d\n", y, x);
#define VI(v) vector<int>v
#define VAI(v, n) vector<int>v[n+2]
#define VPI(v) vector<pair<int,int> >v
#define VAPI(v, n) vector<pair<int,int> >v[n+2]
#define PII pair<int,int>
#define PPI pair<int,pair<int,int> >
#define INF 1000000000
#define FOR(i, x) for(int i=0;i<x;i++)

using namespace std;

int main(){

    int t, testcase = 1;
    IN1(t);

    while(t--){

        ll n, y;
        cin>>n>>y;

        ll val = n * (n+1ll);
        val/=2ll;

        if(n%2ll != 0ll){

            if((y - val)>=0 and (y - val) % n == 0ll)
                cout<<"Yes\n";

            else cout<<"No\n";

        }

        else{

            ll lmt = n*((n/2ll)-1ll);
            lmt+=val;
            if(y <= lmt){

                if((y - val)>=0 and (y - val) % n == 0ll)
                    cout<<"Yes\n";

                else cout<<"No\n";
            }

            else{

                if((y - lmt)%(n/2ll)==0)
                    cout<<"Yes\n";

                else cout<<"No\n";

            }

        }

    }

    return 0;
}