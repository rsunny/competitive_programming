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

VAI(v, 20001);
VAI(vt, 20001);
int x, y, n, m, visited[20001], comp, indeg[20001], outdeg[20001];
stack<int> st;

void dfs(int i){

	FOR(j, v[i].size()){

		if(!visited[v[i][j]]){

			visited[v[i][j]] = 1;
			dfs(v[i][j]);

		}

	}

	st.push(i);
	return;

}

void dfs1(int i){

	int cnt = 0;

	FOR(j, v[i].size()){

		if(!visited[v[i][j]]){

			visited[v[i][j]] = 1;
			dfs1(v[i][j]);

		}

	}
	if((int)v[i].size() == 0)
		comp++;

	visited[i] = 2;
	return;

}

int main(){

	int t;
	IN1(t);

	FOR(tc, t){

		FOR(i, 20001){

			v[i].clear();
			vt[i].clear();

		}

		memset(visited, 0, sizeof visited);
		memset(indeg, 0, sizeof indeg);
		memset(outdeg, 0, sizeof outdeg);
		
		comp = 0;

		while(st.size())
			st.pop();

		IN2(n, m);
		FOR(i, m){

			IN2(x, y);
			v[x].pb(y);
			indeg[y]++;

		}

		FOR(i, n){

			if(!visited[i+1]){

				visited[i+1] = 1;
				dfs(i+1);

			}
		}

		memset(visited, 0, sizeof visited);
		int flag = 0;

		while(st.size()){

			int top = st.top();
			st.pop();

			if(!visited[top]){

				visited[top] = 1;
				dfs1(top);

				if(indeg[top] == 0){

					if(flag == 0)
						flag = 1;

					else comp++;

				}

			}

		}

		OUT1(comp, tc+1);

	}

	return 0;
}
