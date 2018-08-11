#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string.h>
#include <queue>

using namespace std;

int ex,ey,n,t,m,q,x,y,type,res;
long long int ans;
int **wall[2];
int **vis;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int cnt;

void bfs(int x,int y){
    cnt=0;
    queue<int>X,Y;
    X.push(x),Y.push(y);
    vis[x][y]=1;
    while(X.size()){
        cnt++;
        x=X.front(),y=Y.front();
        X.pop(),Y.pop();
        for(int i=0;i<4;i++){
            if(x+dx[i]>0 and x+dx[i]<=n and y+dy[i]>0 and y+dy[i]<=m){
                if(!wall[0][min(x,x+dx[i])][y] and !wall[1][x][min(y,y+dy[i])] and !vis[x+dx[i]][y+dy[i]])
                    vis[x+dx[i]][y+dy[i]]=1,X.push(x+dx[i]),Y.push(y+dy[i]);
            }
        }   
    }
}


int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&n,&m,&q);
        vis = new int*[n+9];
        for(int i=0;i<=n;i++)
            vis[i] = new int[m+9];
        for(int i=0;i<2;i++){
            wall[i] = new int*[n+9];
            for(int j=0;j<=n;j++)
                wall[i][j] = new int[m+9];
        }
        for(int i=0;i<2;i++)
            for(int j=0;j<=n;j++)
                for(int k=0;k<=m;k++)
                    wall[i][j][k]=0;
        ans=0;
        while(q--){
            scanf("%d",&type);
            if(type==1){
                scanf("%d %d",&x,&y);
                wall[1][x][y]=1;
            }
            else if(type==2){
                scanf("%d %d",&x,&y);
                wall[0][x][y]=1;
            }
            else if(type==3){
                scanf("%d %d",&x ,&y );
                scanf("%d %d",&ex,&ey);
                for(int i=0;i<=n;i++)
                    for(int j=0;j<=m;j++)
                        vis[i][j]=0;
                bfs(x,y);
                ans+=vis[ex][ey];
            }
            else if(type==4){
                res=0;
                for(int i=0;i<=n;i++)
                    for(int j=0;j<=m;j++)
                        vis[i][j]=0;
                for(int i=1;i<=n;i++)
                    for(int j=1;j<=m;j++)
                        if(!vis[i][j]){
                            bfs(i,j);
                            res=max(res,cnt);
                        }
                ans+=res;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
