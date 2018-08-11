#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int tree[5*200000];

void update(int lo,int hi,int i,int up_lo,int up_hi,int x){
    if(hi<up_lo or lo>up_hi)
        return;
    if(lo>=up_lo and hi<=up_hi){
        tree[i]=x;
        return;
    }
    int mid=(lo+hi)/2;
    update(lo,mid,2*i,up_lo,up_hi,x);
    update(mid+1,hi,2*i+1,up_lo,up_hi,x);
    return;
}

int query(int lo,int hi,int i,int quer_lo){
    //cout<<lo<<" "<<hi<<" "<<i<<" "<<quer_lo<<"\n";
    if(hi<quer_lo or lo>quer_lo)
        return -1;
    if(lo==hi and lo==quer_lo){
        if(tree[i]!=0)
            return tree[i];
        return lo;
    }
    if(lo<=quer_lo and hi>=quer_lo and tree[i]!=0){
        return tree[i];
    }
    int mid=(lo+hi)/2;
    return max(query(lo,mid,2*i,quer_lo),query(mid+1,hi,2*i+1,quer_lo));
}

class UF    {
    int *id, cnt, *sz;
    public:
    // Create an empty union find data structure with N isolated sets.
    UF(int N)   {
        cnt = N;
        id = new int[N];
        sz = new int[N];
            for(int i=0; i<N; i++)  {
                id[i] = i;
            sz[i] = 1;
        }
    }
    ~UF()   {
    delete [] id;
    delete [] sz;
    }
    // Return the id of component corresponding to object p.
    int find(int p) {
        int root = p;
        while (root != id[root])
            root = id[root];
        while (p != root) {
            int newp = id[p];
            id[p] = root;
            p = newp;
        }
        return root;
    }
    // Replace sets containing x and y with their union.
    void merge(int x, int y)    {
        int i = find(x);
        int j = find(y);
        if (i == j) return;
        
        // make smaller root point to larger one
        if   (sz[i] < sz[j])    { 
            id[i] = j; 
            sz[j] += sz[i]; 
        } else  { 
            id[j] = i; 
            sz[i] += sz[j]; 
        }
            cnt--;
    }
    // Are objects x and y in the same set?
    bool connected(int x, int y)    {
        return find(x) == find(y);
    }
    // Return the number of disjoint sets.
    int count() {
        return cnt;
    }
};

int main(){
    int n,q,type,x,y;
    scanf("%d %d",&n,&q);
    UF dsu(n+9);
    while(q--){
        scanf("%d %d %d",&type,&x,&y);
        if(type==1){
            dsu.merge(x,y);
        }
        else if(type==2){
            while(x<y){
                dsu.merge(x,y);
                x=dsu.find(x);
            }
        }
        else{
            if(dsu.connected(x,y))
                cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}