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

struct segNode{
    vector<int> idx;
};

int id,ele,cnt,res,n1,n2;
int result;
int arr[MAX_N];
int rcmp[MAX_N];
segNode tree[4*MAX_N];
vector<int> range[MAX_N];
unordered_map<int,int> cmp;

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
    return ;
}

int query(int snode,int l, int r){
    int tl=lower_bound(tree[snode].idx.begin(),tree[snode].idx.end(),l)-tree[snode].idx.begin();
    int tr=upper_bound(tree[snode].idx.begin(),tree[snode].idx.end(),r)-tree[snode].idx.begin();
    if(tr==(int)tree[snode].idx.size() or tree[snode].idx[tr]>r)
        tr--;
    if(tl>tr)
        return 0;
    int res=tr-tl+1;
    return res;
}

int getk(int snode,int tl,int tr,int l,int r,int L,int R){
    if(r<l)
        return 0;
    if(tl==l and tr==r){
        return query(snode,L,R);
    }
    CHILDREN;
    return getk(cl,tl,tm,l,min(r,tm),L,R)+getk(cr,tm+1,tr,max(l,tm+1),r,L,R);
}


int main(){
    vector<int> ele;
    map<int,bool> srt;
    int n,q,cnt=1;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        srt[arr[i]]=true;
    }
    map<int,bool> :: iterator it;
    for(it=srt.begin();it!=srt.end();it++){
        ele.push_back(it->first);
        cmp[it->first]=cnt;   
        rcmp[cnt]=it->first;
        cnt++;                   
    }
    for(int i=1;i<=n;i++){
        range[cmp[arr[i]]].push_back(i);
    }
    srt.clear();
    build(1,1,cnt-1);
    int l,r,k,a,b;
    scanf("%d", &q);
    while(q--){
        scanf("%d %d %d",&a,&b,&k);
        l=result^a;l=max(l,1);
        r=result^b;r=min(r,n);
        if(r<l)
            result=0;
        else{
            int tl=upper_bound(ele.begin(),ele.end(),k)-ele.begin();tl++;
            result=getk(1,1,cnt-1,tl,cnt-1,l,r);
        }
        printf("%d\n",result);
    }
    return 0;
}