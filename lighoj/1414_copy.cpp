#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

#define INF 1000

const int N = 109;
const int mod = (1e9)+7;

int f[N][N][N*3],p[N][N][N*3];
int n,m,K;
string a, b, c, years;
int nxt[N*3][26];
 
void init()
{
    int i, j;
    memset(nxt,-1,sizeof nxt);
    for(i=0;i<=K-1;i++)
    {
        for(j=0;j<26;j++) nxt[i][j]=nxt[i+1][j];
        nxt[i][c[i]-'a']=i;
    }
}
 
void up ( int & x, int y)
{
    x += y;
    if(x>=mod) x-=mod;
}
 
int check ( string a, int i, int n, int k)
{
    int x,t;
    for(x=i;x<n;x++)
    {
        t=a[x]-'a';
        if(nxt[k][t]==-1) return 0;
        k=nxt[k][t]+1;
    }
    return 1;
}
 
int DFS ( int i, int j, int k)
{
    if(i==n)
    {
        if(check(b,j,m,k)) return m-j;
        return INF;
    }
    if(j==m)
    {
        if(check(a,i,n,k)) return n-i;
        return INF;
    }
    if(f[i][j][k]!=-1) return f[i][j][k];
    int ans = INF;
    if(a[i]==b[j])
    {
        if(nxt[k][a[i]-'a']>=0)
        {
            ans=min(ans,DFS(i+1,j+1,nxt[k][a[i]-'a']+1)+1);
        }
    }
    else
    {
        if(nxt[k][a[i]-'a']>=0)
        {
            ans=min(ans,DFS(i+1,j,nxt[k][a[i]-'a']+1)+1);
        }
        if(nxt[k][b[j]-'a']>=0)
        {
            ans=min(ans,DFS(i,j+1,nxt[k][b[j]-'a']+1)+1);
        }
    }
    return f[i][j][k]=ans;
}
 
 
int DFS1 ( int i, int j, int k)
{
    if(i==n||j==m) return 1;
    if(p[i][j][k]!=-1) return p[i][j][k];
    int ans = 0, x;
    if(a[i]==b[j])
    {
        x=nxt[k][a[i]-'a'];
        if(x!=-1&&DFS(i+1,j+1,x+1)+1==f[i][j][k]) up(ans,DFS1(i+1,j+1,x+1));
    }
    else
    {
        x=nxt[k][a[i]-'a'];
        if(x!=-1&&DFS(i+1,j,x+1)+1==f[i][j][k]) up(ans,DFS1(i+1,j,x+1));
        x=nxt[k][b[j]-'a'];
        if(x!=-1&&DFS(i,j+1,x+1)+1==f[i][j][k]) up(ans,DFS1(i,j+1,x+1));
    }
    return p[i][j][k]=ans;
}
 
 
string ans;
 
 
void DFS2 ( int i, int j, int k)
{
    if(i==n)
    {
        ans+=b.substr(j,m-j);
        return;
    }
    if(j==m)
    {
        ans+=a.substr(i,n-i);
        return;
    }
    int L=f[i][j][k],x,y;
    if(a[i]==b[j])
    {
        ans+=a[i];
        x=nxt[k][a[i]-'a'];
        DFS2(i+1,j+1,x+1);
    }
    else
    {
        x=nxt[k][a[i]-'a'];
        y=nxt[k][b[j]-'a'];
        if(x!=-1&&y!=-1&&L==DFS(i+1,j,x+1)+1&&L==DFS(i,j+1,y+1)+1)
        {
            if(a[i]<b[j])
            {
                ans+=a[i];
                DFS2(i+1,j,x+1);
            }
            else
            {
                years += b [j];
                DFS2(i,j+1,y+1);
            }
        }
        else if(x!=-1&&L==DFS(i+1,j,x+1)+1)
        {
            ans+=a[i];
            DFS2(i+1,j,x+1);
        }
        else
        {
            years += b [j];
            DFS2(i,j+1,y+1);
        }
    }
}
 
 
void deal ()
{
    memset(f,-1,sizeof f);
    memset(p,-1,sizeof p);
    int minLen=DFS(0,0,0);
    if(minLen>=INF)
    {
        cout<<"0\nNOT FOUND\n";
        return;
    }
    int cnt=DFS1(0,0,0);
    cout<<cnt<<"\n";
    years = "" ;
    DFS2(0,0,0);
    cout<<years<<"\n";
    return ;
}
 
 
int main ()
{
    int num = 0;
    {
        cin>>a; n=a.size();
        cin>>b; m=b.size();
        cin>>c; K=c.size();
        init();
        printf("Case %d: ",++num);
        deal();
    }
    return 0;
}