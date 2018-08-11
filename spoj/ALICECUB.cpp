#include <iostream>
#include <vector>
#include <utility>
#include <string.h>
#include <queue>

using namespace std;

#define pb push_back
#define mp make_pair

bool vis[1<<17];
int lvl[1<<17];
vector<pair<int,int> > adj;

void BFS(int num){
	memset(vis,false,sizeof vis);
	for(int i=0;i<(1<<17);i++)
		lvl[i]=5;
	queue<int> config, level;
	config.push(num),level.push(0);
	int lev=0;
	vis[num]=true;
	while(config.size()){
		num=config.front(),lev=level.front();
		lvl[num]=lev;
		config.pop(),level.pop();		
		int temp1,temp2,temp,f,s;
		for(int i=0;i<(int)adj.size();i++){
			temp=num,temp1=num,temp2=num;
			f=adj[i].first,s=adj[i].second;
			temp1&=(1<<f);
			temp2&=(1<<s);
			if(temp1!=temp2){
				temp^=(1<<f);
				temp^=(1<<s);
				if(!vis[temp] and lev<3)
					vis[temp]=true,config.push(temp),level.push(lev+1);
			}
		}
	}
	return ;
}

int main() {
	int t;
	int final=0;
	scanf("%d",&t);
	for(int i=9;i<=16;i++){
		final|=(1<<i);
	}
	adj.pb(mp(1,2)),adj.pb(mp(1,3)),adj.pb(mp(1,5)),adj.pb(mp(1,9));
	adj.pb(mp(2,4)),adj.pb(mp(2,6)),adj.pb(mp(2,10)),adj.pb(mp(3,4));
	adj.pb(mp(3,7)),adj.pb(mp(11,3)),adj.pb(mp(4,8)),adj.pb(mp(4,12));
	adj.pb(mp(5,6)),adj.pb(mp(5,7)),adj.pb(mp(5,13)),adj.pb(mp(6,14));
	adj.pb(mp(6,8)),adj.pb(mp(7,8)),adj.pb(mp(7,15)),adj.pb(mp(8,16));
	adj.pb(mp(9,10)),adj.pb(mp(11,9)),adj.pb(mp(9,13)),adj.pb(mp(10,14));
	adj.pb(mp(11,12)),adj.pb(mp(15,11)),adj.pb(mp(12,16)),adj.pb(mp(13,14));
	adj.pb(mp(13,15)),adj.pb(mp(14,16)),adj.pb(mp(15,16)),adj.pb(mp(10,12));
	BFS(final);
	for(int test=1;test<=t;test++){
		int bit=0;
		int num=0;
		for(int i=1;i<=16;i++){
			scanf("%d",&bit);
			num|=(bit<<i);
		}
		printf("Case #%d: ",test);
		lvl[num]>3?printf("more\n"):printf("%d\n",lvl[num]);
	}
	return 0;
}