#include <iostream>
#include <cstdio>

using namespace std;

int a[10000000][2],ww[20],sz[10000000],type,root[600000],m,ind[10000000];
int ans,n,v,l,r,x;

void add(int prev_root, int now_root, int x) {
    for (int i=18;i>=0;i--) {
        int edge=(x & (1 << i));
        if (edge!=0) edge=1;
        v++;
        ww[i]=now_root;
        ind[v]=n;
        a[now_root][edge]=v;
        a[now_root][1-edge]=a[prev_root][1-edge];
        sz[now_root]=sz[a[now_root][1-edge]];
        now_root=v;
        prev_root=a[prev_root][edge];
    }
    sz[now_root]+=sz[prev_root]+1;
    for (int i=0;i<=18;i++) sz[ww[i]]=sz[a[ww[i]][0]]+sz[a[ww[i]][1]];
}

void findkth(int vr, int vl, int x) {
    for (int i=18;i>=0;i--) {
        for (int j=0;j<=1;j++)
            if (sz[a[vr][j]]-sz[a[vl][j]]<x) x-=sz[a[vr][j]]-sz[a[vl][j]];
            else {
                vr=a[vr][j];
                vl=a[vl][j];
                ans+=j*(1 << i);
                break;
            }
    }
}

int main() {
    scanf("%d",&m);
    for (int query=1;query<=m;query++) {
        scanf("%d%d%d",&l,&r,&x);
        ans=0;
        findkth(root[r],root[l-1],x);
        printf("%d\n",ans);
    }
    return 0;
}
 