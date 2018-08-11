#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <cassert>
#include <vector>

using namespace std;

int n,m,q;
int f[25],s[25]; 
long long int st[55][25];
long long int bad[25];
bool vis[25];
bool vis1[55];

struct grp{
	int a,b,c,d,e;
	bool operator<(grp g) const{
        return a<g.a;
    }

};

int main(){
	scanf("%d %d",&m,&n);
	scanf("%d",&q);
	assert(n>=1 and n<=21 and m>=1 and m<=50 and q>=1 and q<=30);

	for(int j=0;j<n;j++)
		scanf("%lld",&bad[j]),assert(bad[j]>=1 and bad[j]<=(int)1e6);

	for(int i=1;i<=m;i++)
		for(int j=0;j<n;j++)
			scanf("%lld",&st[i][j]),assert(st[i][j]>=1 and st[i][j]<=(int)1e6);

	for(int i=1;i<=q;i++)
		scanf("%d %d",&f[i],&s[i]),assert(f[i]>=1 and f[i]<=n),assert(s[i]>=1 and s[i]<=n),f[i]--,s[i]--;

	vector<pair<long long int,grp> >v;
	for(int i=1;i<=q;i++){
		for(int j=i+1;j<=q;j++){
			if(f[i]!=f[j] and s[i]!=f[j] and f[i]!=s[j] and s[i]!=s[j]){
				for(int sg=0;sg<m;sg++){
					long long int temp=(max(st[sg+1][f[i]],st[sg+1][s[i]])*max(st[sg+1][f[j]],st[sg+1][s[j]]));
					grp g; g.a=f[i],g.b=s[i],g.c=f[j],g.d=s[j],g.e=sg+1;
					v.push_back(make_pair(temp,g));
				}
			}
		}
	}
	sort(v.rbegin(), v.rend());
	long long int res=0;
	for(int i=0;i<(int)v.size();i++){
		if(!vis[v[i].second.a] and !vis[v[i].second.b] and !vis[v[i].second.c] and !vis[v[i].second.d] and !vis1[v[i].second.e]){
			vis[v[i].second.a]=vis[v[i].second.b]=vis[v[i].second.c]=vis[v[i].second.d]=vis1[v[i].second.e]=true;
			res+=v[i].first;
		}	
	}
	for(int i=0;i<n;i++)
		if(!vis[i])
			res-=bad[i];
	printf("%lld\n",res);
	return 0;
}