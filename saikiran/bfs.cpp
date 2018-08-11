#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <stdio.h>

#define fir first
#define sec second
#define ll long long
#define INF (int)1e9
#define pb push_back
#define mp make_pair

using namespace std;

vector<pair<int,int> >v[100010];
pair<int,int> dist[100010];

int main(){
	//ifstream cin("testing1.txt");
	int n,m,x,y,z;
	int src,dest,flag=0;
	cin>>n>>m;
	cin>>src>>dest;
	for(int i=0;i<m;i++){
		//cin>>x>>y>>z;
		scanf("%d %d %d",&x,&y,&z);
		v[x].pb(mp(y,z));
		v[y].pb(mp(x,z));
	}
	for(int i=0;i<n+1;i++){
		dist[i].fir=dist[i].sec=INF;
	}
	queue<pair<int,pair<int,int> > >q;
	q.push(mp(0,mp(0,src)));
	cout<<"here\n";
	while(!q.empty()){
		x=q.front().fir;
		y=q.front().sec.fir,z=q.front().sec.sec;
		q.pop();
		// if(z==dest){
		// 	cout<<x-1<<" "<<y<<endl;
		// 	break;
		// }
		for(int i=0;i<v[z].size();i++){
			if(x+1<dist[v[z][i].fir].fir){
				dist[v[z][i].fir].fir=x+1;
				dist[v[z][i].fir].sec=y+v[z][i].sec;
				q.push(mp(x+1,mp(y+v[z][i].sec,v[z][i].fir)));
			}
			else if(x+1==dist[v[z][i].fir].fir){
				if(y+v[z][i].sec<dist[v[z][i].fir].sec){
					dist[v[z][i].fir].sec=y+v[z][i].sec;
					q.push(mp(x+1,mp(y+v[z][i].sec,v[z][i].fir)));
				}
			}
		}
	}
	if(dist[dest].fir>=INF and dist[dest].sec>=INF){
		cout<<"-1 -1\n";

	}
	else cout<<dist[dest].fir-1<<" "<<dist[dest].sec<<endl;
	return 0;
}