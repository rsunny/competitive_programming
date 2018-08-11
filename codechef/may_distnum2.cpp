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

#define MAX_N 100010
#define CHILDREN int tm = (tl+tr)>>1; \
                    int cl = snode<<1; \
                    int cr = cl|1

struct node{
    int n,l,r;
};

struct segNode{
    int num;
    vector<int> idx;
    vector<int> root;
    vector<node> buf;
};

node dummy;
int id,ele,cnt,res,result,n1,n2;
int global_snode;
int arr[MAX_N];
int rcmp[MAX_N];
int leaf[4*MAX_N];
segNode tree[4*MAX_N];
vector<int> range[MAX_N];
unordered_map<int,int> cmp;

int insert(int id,int l,int r,int p,int v){
    int idx = ++tree[global_snode].num;
    tree[global_snode].buf.push_back(tree[global_snode].buf[id]);
    if(l == r){
        tree[global_snode].buf[idx].n += v;
        return idx;
    }
    int mid = (l + r) / 2;
    if(p <= mid) tree[global_snode].buf[idx].l = insert(tree[global_snode].buf[idx].l,l,mid,p,v);
    else         tree[global_snode].buf[idx].r = insert(tree[global_snode].buf[idx].r,mid+1,r,p,v);
    tree[global_snode].buf[idx].n = tree[global_snode].buf[tree[global_snode].buf[idx].l].n + tree[global_snode].buf[tree[global_snode].buf[idx].r].n;
    return idx;
}

int query(int id,int l,int r,int s,int e){  
    if(l == s && r == e)
        return tree[global_snode].buf[id].n;
    int mid = (l + r) / 2;
    int ans = 0;
    if(s <= mid)
        ans += query(tree[global_snode].buf[id].l,l,mid,s,min(mid,e));
    if(e > mid)
        ans += query(tree[global_snode].buf[id].r,mid+1,r,max(s,mid+1),e);
    return ans;
}

int gtl,gtr;

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
    tree[snode].root.push_back(0);
    tree[snode].buf.push_back(dummy);
    tree[snode].root[0]=0;
    tree[snode].num=0;
    cnt=1;
    unordered_map<int,int> nxt;
    global_snode=snode;
    for(int i=0;i<n;i++){
        id=tree[snode].idx[i];
        ele=arr[id];
        if(!nxt[ele])
            tree[snode].root.push_back(insert(tree[snode].root[i],1,n,i+1,1));
        else{
            int temproot = insert(tree[snode].root[i],1,n,nxt[ele],-1);
            tree[snode].root.push_back(insert(temproot,1,n,i+1,1));
        }
        nxt[ele] = i+1;
    }
    for(int i=1;i<=n;i++){
        assert(gtl<=cmp[arr[tree[snode].idx[i-1]]] and cmp[arr[tree[snode].idx[i-1]]]<=gtr);
        set<int> s;
        for(int j=i;j<=n;j++){
            s.insert(arr[tree[snode].idx[j-1]]);
            int res=query(tree[snode].root[j],1,n,i,j);
            assert((int)s.size()==res);
        }
    }
    return ;
}

void build(int snode,int tl,int tr){
    if(tl==tr){
        tree[snode].idx=range[tl];
        leaf[snode]=1;
        return;
    }
    CHILDREN;
    build(cl,tl,tm);
    build(cr,tm+1,tr);
    gtl=tl, gtr=tr;
    merge(snode,cl,cr);
}

int query(int snode,int l, int r){
    // cout<<"In query func\n";
    // int tl=tree[snode].idx.size();
    // int tr=-1;
    // cout<<l<<" "<<r<<"\n";
    // for(int i=0;i<(int)tree[snode].idx.size();i++){
    //     cout<<tree[snode].idx[i]<<" ";
    // }
    // cout<<"\n";

    // for(int i=(int)tree[snode].idx.size()-1;i>=0;i--){
    //     if(tree[snode].idx[i]<l)
    //         break;
    //     tl=i;
    // }
    // for(int i=0;i<(int)tree[snode].idx.size();i++){
    //     if(tree[snode].idx[i]>r)
    //         break;
    //     tr=i;
    // }
    // cout<<tl<<" "<<tr<<"\n";
    // cout<<"\n";
    // cout<<tl+1<<" "<<tr+1<<"\n";
    int tl=lower_bound(tree[snode].idx.begin(),tree[snode].idx.end(),l)-tree[snode].idx.begin();
    int tr=upper_bound(tree[snode].idx.begin(),tree[snode].idx.end(),r)-tree[snode].idx.begin();
    if(tr==(int)tree[snode].idx.size() or tree[snode].idx[tr]>r)
        tr--;
    if(tl>tr or tl==tree[snode].idx.size() or tr==-1)
        return 0;
    int n=(int)tree[snode].idx.size();
    global_snode=snode;
    if(leaf[snode])
        return 1;
    int res=query(tree[snode].root[tr+1],1,n,tl+1,tr+1);
    //cout<<"Out query func\n";
    return res;
}

void getk(int snode,int tl,int tr,int l,int r,int k){
    //cout<<snode<<" "<<tl<<" "<<tr<<" "<<l<<" "<<r<<" "<<k<<"\n";
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
    // srand(time(NULL));
     scanf("%d %d", &n, &q);
    // n=rand()%1000 + 5;
    // q=1000;
    // cout<<n<<" "<<q<<"\n";
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        // arr[i]=rand()%100+5;
        // cout<<arr[i]<<" ";
        srt[arr[i]]=true;
    }
    //cout<<"\n";
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
    int res=0;
    cout<<"in query\n";
    int Q=1;
    while(q--){
        result=max(result,0);
        scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);
        L=a; L*=result; L+=b; L%=n; L++; l=L;
        R=c; R*=result; R+=d; R%=n; R++; r=R;
        if(r<l)
            swap(l,r);
        res=query(1,l,r);
        if(res<k)
            result=-1;
        else
            getk(1,1,cnt-1,l,r,k);
        set<int> s;
        for(int i=l;i<=r;i++)
            s.insert(arr[i]);
        int bres=-1;
        if(s.size()>=k){
            for(int i=1;i<k;i++)
                s.erase(s.begin());
            bres=*(s.begin());
        }
        cout<<Q++<<" ";
        cout<<bres<<" ";
        cout<<result<<"\n";
        assert(bres==result);
    }
    return 0;
}