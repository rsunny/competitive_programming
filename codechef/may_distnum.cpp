#include <cstdio>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <iostream>
#include <map>
#include <algorithm>
#include <cassert>
#include <set>

using namespace std;

#define MAX_N 100003
#define CHILDREN int tm = (tl+tr)>>1; \
                    int cl = snode<<1; \
                    int cr = cl|1

struct node{
    int count;
    node *left, *right;

    node(int count, node *left, node *right):
        count(count), left(left), right(right) {}

    node * insert(int l,int r,int w,int val,node *null){
        if(l<=w and w<=r){
            if(l==r and r==w){
                return new node(val, null, null);
            }
            int m = (l+r)/2;
            node* left = this->left->insert(l, m, w, val, null);
            node* right= this->right->insert(m+1, r, w, val, null);
            return new node(left->count+right->count, left, right);
        }

        return this;
    }
};

struct segNode{
    vector<int> idx;
    vector<node*> root;
};

int id,ele,cnt,res,n1,n2;
long long int result;
int arr[MAX_N];
int rcmp[MAX_N];
int leaf[4*MAX_N];
segNode tree[4*MAX_N];
vector<int> range[MAX_N];
unordered_map<int,int> cmp;

int query(node *a, int tl,int tr,int l,int r, node *null){
    if(r<l or a==null)
        return 0;
    if(tl==l and tr==r){
        return a->count;
    }
    int tm = (tl+tr)>>1;
    return query(a->left,tl,tm,l,min(r,tm),null)+query(a->right,tm+1,tr,max(l,tm+1),r,null);
}

void merge(int snode,int cl, int cr){
    n1=tree[cl].idx.size();
    n2=tree[cr].idx.size();
    int i=0;int j=0;
    while (i < n1 && j < n2){
        if (tree[cl].idx[i] <= tree[cr].idx[j]){
            tree[snode].idx.push_back(tree[cl].idx[i]);
            i++;
        }
        else{
            tree[snode].idx.push_back(tree[cr].idx[j]);
            j++;
        }
    }
    while (i < n1){
        tree[snode].idx.push_back(tree[cl].idx[i]);
        i++;
    }
    while (j < n2){
        tree[snode].idx.push_back(tree[cr].idx[j]);
        j++;
    }

    int n=tree[snode].idx.size();
    tree[snode].root.resize(n+3);
    node *null = new node(0, NULL, NULL);
    null->left = null->right = null;
    tree[snode].root[0]=null;
    unordered_map<int,int> lst;
    for(int i=1;i<=n;i++){
        id=tree[snode].idx[i-1];
        ele=arr[id];
        tree[snode].root[i]=tree[snode].root[i-1]->insert(1,n,i,1,null);
        if(lst[ele]){
            tree[snode].root[i]=tree[snode].root[i]->insert(1,n,lst[ele],0,null);
        }
        lst[ele]=i;
    }
    return ;
}

void build(int snode,int tl,int tr){
    if(tl==tr){
        tree[snode].idx=range[tl];
        merge(snode,0,0);
        return;
    }
    CHILDREN;
    build(cl,tl,tm);
    build(cr,tm+1,tr);
    merge(snode,cl,cr);
}

int query(int snode,int l, int r){

    int n=(int)tree[snode].idx.size();
    int tl=lower_bound(tree[snode].idx.begin(),tree[snode].idx.end(),l)-tree[snode].idx.begin();
    int tr=upper_bound(tree[snode].idx.begin(),tree[snode].idx.end(),r)-tree[snode].idx.begin();
    if(tr==(int)tree[snode].idx.size() or tree[snode].idx[tr]>r)
        tr--;
    if(tl>tr)
        return 0;
    int res=query(tree[snode].root[tr+1],1,n,tl+1,tr+1,tree[snode].root[0]);
    return res;
}

void getk(int snode,int tl,int tr,int l,int r,int k){
    if(tl==tr){
        result=rcmp[tl];
        return ;
    }
    CHILDREN;

    res=query(cl,l,r);
    if(res<k){
        k-=res;
        getk(cr,tm+1,tr,l,r,k);
        return ;
    }
    getk(cl,tl,tm,l,r,k);
    return ;
}

int main(){
    map<int,bool> srt;
    int n,q,cnt=1;
     scanf("%d %d", &n, &q);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        srt[arr[i]]=true;
    }
    map<int,bool> :: iterator it;
    for(it=srt.begin();it!=srt.end();it++){
        cmp[it->first]=cnt;   
        rcmp[cnt]=it->first;
        cnt++;                   
    }
    for(int i=1;i<=n;i++){
        range[cmp[arr[i]]].push_back(i);
    }
    srt.clear();
    build(1,1,cnt-1);
    long long int L,R;
    int l,r,k,a,b,c,d;
    while(q--){
        result=max(result,0LL);
        scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);
        L=a; L*=result; L+=b; L%=n; L++; l=L;
        R=c; R*=result; R+=d; R%=n; R++; r=R;
        if(r<l)
            swap(l,r);
        if(query(1,l,r)<k)
            result=-1;
        else
            getk(1,1,cnt-1,l,r,k);
        cout<<result<<"\n";
    }
    return 0;
}