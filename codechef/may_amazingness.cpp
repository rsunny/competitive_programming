#include <cstdio>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <iostream>
#include <set>
#include <algorithm>
#include <cassert>

using namespace std;

#define MAX_N 100010
#define CHILDREN int tm = (tl+tr)>>1; \
                    int cl = snode<<1; \
                    int cr = cl|1

struct node{
    int count;
    node *left, *right;

    node(int count, node *left, node *right):
        count(count), left(left), right(right) {}

    node* insert(int l, int r, int w, int val, node* null);
};

struct segNode{
    vector<int> idx;
    vector<node*> root;
};

int id,ele,cnt,res,result,n1,n2;
int arr[MAX_N];
int sarr[MAX_N];
int rcmp[MAX_N];segNode tree[4*MAX_N];
vector<int> range[MAX_N];
vector<int> com[MAX_N];
unordered_map<int,int> cmp;
unordered_map<int,int> treecmp;
unordered_map<int,int> nxt;
unordered_map<int,int> leaf;

node * node::insert(int l,int r,int w,int val,node *null){
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

int query(node *a, int tl,int tr,int l,int r,node *null){
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

    node *null = new node(0, NULL, NULL);
    null->left = null->right = null;
    int n=tree[snode].idx.size();
    tree[snode].root.resize(n+9);
    tree[snode].root[0]=null;
    cnt=1;

    for(int i=1;i<=n;i++){
        id=tree[snode].idx[i-1];
        ele=arr[id];
        if(!treecmp[ele])
            treecmp[ele]=cnt,cnt++;
        com[treecmp[ele]].push_back(i);
    }
    for(int i=1;i<=n;i++){
        id=tree[snode].idx[i-1];
        ele=arr[id];
        ele=treecmp[ele];
        tree[snode].root[i]=tree[snode].root[i-1]->insert(1,n,i,1,null);
        if(nxt[ele]){
            tree[snode].root[i]=tree[snode].root[i]->insert(1,n,com[ele][nxt[ele]-1],0,null);
        }
        nxt[ele]++;
    }
    //cout<<"merge : "<<snode<<"\n";
    for(int i=1;i<=n;i++){
        id=tree[snode].idx[i-1];
        //cout<<id<<" ";
        ele=cmp[arr[id]];
        ele=treecmp[ele];
        com[ele].clear();
    }
    //cout<<"\n";
    nxt.clear();
    treecmp.clear();
    for(int i=1;i<=n;i++){
        set<int> s;
        for(int j=i;j<=n;j++){
            s.insert(arr[tree[snode].idx[j-1]]);
            int res=query(tree[snode].root[j],1,(int)tree[snode].idx.size(),i,j,tree[snode].root[0]);
            if((int)s.size()!=res){
                cout<<"failed : "<<snode<<" "<<i<<" "<<j<<" "<<res<<" "<<s.size()<<"\n";
                for(int k=i;k<=j;k++)
                    cout<<tree[snode].idx[k-1]<<" ";
                cout<<"\n";
            }
        }
    }
    return ;
}

void build(int snode,int tl,int tr){
    //cout<<"build\n";
    //cout<<snode<<" "<<tl<<" "<<tr<<"\n";
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
    //cout<<snode<<" "<<l<<" "<<r<<"\n";
    int tl=tree[snode].idx.size();
    int tr=-1;
    // for(int i=0;i<(int)tree[snode].idx.size();i++)
    //     cout<<(int)tree[snode].idx[i]<<" ";
    // cout<<"\n";
    for(int i=(int)tree[snode].idx.size()-1;i>=0;i--){
        if(tree[snode].idx[i]<l)
            break;
        //cout<<i<<" ";
        tl=i;
    }
    //cout<<"\n";
    for(int i=0;i<(int)tree[snode].idx.size();i++){
        if(tree[snode].idx[i]>r)
            break;
        //cout<<i<<" ";
        tr=i;
    }
    // cout<<"\n";
    // cout<<tl+1<<" "<<tr+1<<"\n";
    // int tl=lower_bound(tree[snode].idx.begin(),tree[snode].idx.end(),l)-tree[snode].idx.begin();
    // int tr=upper_bound(tree[snode].idx.begin(),tree[snode].idx.end(),r)-tree[snode].idx.begin();
    // if(tr==(int)tree[snode].idx.size() or tree[snode].idx[tr]>r)
    //     tr--;
    // if(tr==-1)
    //     return 0;
    // if(tl==tree[snode].idx.size() or tr==-1)
    //     return 0;
    // if(leaf[snode])
    //     return 1;
    int res=query(tree[snode].root[tr+1],1,(int)tree[snode].idx.size(),tl+1,tr+1,tree[snode].root[0]);
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
    set<int> srt;
    int n,q,cnt=1;
    srand(time(NULL));
    n = rand()%10000 + 6;n=100000;
    q = rand()%1000 + 6;q=100000;
    //scanf("%d %d", &n, &q);
    cout<<n<<" "<<q<<"\n";
    for(int i=1;i<=n;i++){
        //scanf("%d",&arr[i]);
        arr[i]=rand()%(int)(1e9);arr[i]++;
        cout<<arr[i]<<" ";
        //srt.insert(arr[i]);
    }
    cout<<"\n";
    // set<int> :: iterator it;
    // for(it=srt.begin();it!=srt.end();it++){
    //     cmp[*it]=cnt;   
    //     rcmp[cnt]=*it;
    //     cnt++;                   
    // }
    // for(int i=1;i<=n;i++){
    //     range[cmp[arr[i]]].push_back(i);
    // }
    // srt.clear();
    // build(1,1,cnt-1);
    // long long int L,R;
    int l,r,k,a,b,c,d;
    int res=0;
    while(q--){
        // result=max(result,0);
        // //scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);
        a=rand()%(n+1);b=rand()%(n+1);c=rand()%(n+1);d=rand()%(n+1);k=rand()%(int)sqrt(n) + 1;
        // L=a; L*=result; L+=b; L%=n; L++; l=L;
        // R=c; R*=result; R+=d; R%=n; R++; r=R;
        cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<k<<"\n";
        // if(r<l)
        //     swap(l,r);
        // res=query(1,l,r);
        // if(res<k)
        //     result=-1;
        // else
        //     getk(1,1,cnt-1,l,r,k);
        // //cout<<"answer : ";
        // cout<<result<<"\n";
    }
    return 0;
}