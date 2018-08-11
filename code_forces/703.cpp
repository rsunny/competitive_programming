#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define all(X) (X).begin(),(X).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define s(a) scanf("%d", &a)

struct node{
    int n,l,r;
}buf[20607602];


int N,i,j,Q,a[1000009],num;
unordered_map<int, int> pos;
vector<int> roots;

int insert(int id,int l,int r,int p,int v){
    int idx = ++num;
    buf[idx] = buf[id];
    if(l == r){
        buf[idx].n = v;
        return idx;
    }
    int mid = (l + r) / 2;
    if(p <= mid) buf[idx].l = insert(buf[idx].l,l,mid,p,v);
    else         buf[idx].r = insert(buf[idx].r,mid+1,r,p,v);
    buf[idx].n = buf[buf[idx].l].n ^ buf[buf[idx].r].n;
    return idx;
}

int query(int id,int l,int r,int s,int e){  
    assert(id<=num);
    if(l == s && r == e)
        return buf[id].n;
    int mid = (l + r) / 2;
    int ans = 0;
    if(s <= mid)
        ans ^= query(buf[id].l,l,mid,s,min(mid,e));
    if(e > mid)
        ans ^= query(buf[id].r,mid+1,r,max(s,mid+1),e);
    return ans;
}

int xorsum[1000009];

int main(){
    s(N);
    roots.push_back(0);
    for(i = 0; i < N; i++){
        s(a[i]);
		xorsum[i+1]=xorsum[i]^a[i];
        roots.push_back(0);
        if(!pos[a[i]])
            roots[i+1] = insert(roots[i],1,N,i+1,a[i]);
        else{
            int temproot = insert(roots[i],1,N,pos[a[i]],0);
            roots[i+1] = insert(temproot,1,N,i+1,a[i]);
        }
        pos[a[i]] = i+1;
    } 
    s(Q);
    int ans = 0;
    while(Q--){
        int x,r;
        s(x); s(r);        
        ans = query(roots[r],1,N,x,r);
        ans^=xorsum[r];
        ans^=xorsum[x-1];
        printf("%d\n", ans);
    }   
    
    return 0;
}

