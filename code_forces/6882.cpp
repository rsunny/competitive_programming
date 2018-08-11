#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <queue>

using namespace std;

int arr[100009];
vector<int> ed[100009];
int n;

bool check(int src){
    arr[src]=1;
 
    queue <int> q;
    q.push(src);
 
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int i=0;i<(int)ed[u].size();i++){
        	int v=ed[u][i];
            if(arr[v] == -1){
                arr[v] = 1 - arr[u];
                q.push(v);
            }
            else if (arr[v] == arr[u])
                return false;
        }
    }
    return true;
}

int main(){
	int a,b,w;
	int m;
	cin>>n;
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		ed[a].push_back(b);
		ed[b].push_back(a);
	}
    for(int i=1; i<=n; i++)
		arr[i]=-1;
 	
 	for(int i=1;i<=n;i++){
 		if(arr[i]==-1)
 			if(!check(i)){
 				cout<<-1<<"\n";
 				return 0;
 			}
 	}
	b=0,w=0;
	for(int i=1;i<=n;i++)
		if(arr[i]==1)
			b++;
		else w++;
	cout<<b<<"\n";
	for(int i=1;i<=n;i++)
		if(arr[i]==1)
			cout<<i<<" ";
	cout<<"\n";
	cout<<w<<"\n";
	for(int i=1;i<=n;i++)
		if(arr[i]==0)
			cout<<i<<" ";
	cout<<"\n";
	return 0;
}
