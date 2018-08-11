#include <iostream>
#include <stack>
#include <cstdio>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define rof(i,a,b) for(int (i)=(a);(i) > (b); --(i))
#define mkp make_pair

const int maxn = 1e6 + 100;

int a[maxn], n, m, l[maxn], r[maxn], ans[maxn];
stack<int> s;
unordered_map<int,int> mp;
vector<int> arr;
vector<int> pos[maxn];
long long int cnt[maxn];
vector<long long int> res;
vector<pair<int,int> > q;
vector<char> symbol,person;

void find_range(){
  For(i,0,n){
    while(!s.empty() && a[s.top()] >= a[i])
      s.pop();
    if(!s.empty())
      l[i] = s.top();
    s.push(i);
  }

  while(!s.empty())
    s.pop();
  
  rof(i,n-1,-1){
    while(!s.empty() && a[s.top()] >= a[i])
      s.pop();
    if(!s.empty())
      r[i] = s.top();
    s.push(i);
  }
}

int main(){
  long long int sum,left,right,prev_left,prev_right,pres_pos,prev_pos;
  int num,idx,sz,assign;
  char sym,per;
  string ret="";

  scanf("%d %d", &n,&m);
  For(i,0,n)
    scanf("%d", a + i),a[i]*=-1;

  assign=1;
  int x=0;
  while(m--){
    getchar();
    scanf("%c %d %c",&sym,&num,&per);
    q.push_back(mkp(num,x++));
    symbol.push_back(sym);
    person.push_back(per);
    ret+=" ";
  }

  sort(q.begin(), q.end());
  fill(l, l + maxn, -1);
  fill(r, r + maxn, n);
  find_range();
  
  for(int i=0;i<n;i++){
    a[i]*=-1;
    if(!mp[a[i]]){
      mp[a[i]]=assign;
      assign++;
      arr.push_back(a[i]);
    }
    pos[mp[a[i]]].push_back(i);
  }

  for(int i=0;i<(int)arr.size();i++){
    idx=mp[arr[i]];
    sz=pos[idx].size();
    left =l[pos[idx][0]]+1;
    right=r[pos[idx][0]]-1;
    sum=(pos[idx][0]-left)*(pos[idx][0]-left+1LL); sum/=2LL;
    cnt[idx]-=sum;
    for(int j=1;j<sz;j++){
      pres_pos  =pos[idx][j];     prev_pos   =pos[idx][j-1];
      left      =l[pres_pos]+1;   right      =r[pres_pos]-1;
      prev_left =l[prev_pos]+1;   prev_right =r[prev_pos]-1;
      if(prev_left==left and prev_right==right){
        sum=(pres_pos-prev_pos-1LL)*(pres_pos-prev_pos); sum/=2LL;
        cnt[idx]-=sum;
      }
      else{
        sum=(pres_pos-left)*(pres_pos-left+1LL); sum/=2LL;
        cnt[idx]-=sum;
        sum=(prev_right-prev_pos)*(prev_right-prev_pos+1LL); sum/=2LL;
        cnt[idx]-=sum;
        sum=(prev_right-prev_left+1LL)*(prev_right-prev_left+2LL); sum/=2LL;
        cnt[idx]+=sum;
      }
    }
    left =l[pos[idx][sz-1]]+1;
    right=r[pos[idx][sz-1]]-1;
    sum=(right-pos[idx][sz-1])*(right-pos[idx][sz-1]+1LL); sum/=2LL;
    cnt[idx]-=sum;
    sum=(right-left+1LL)*(right-left+2LL); sum/=2LL;
    cnt[idx]+=sum;
  }

  arr.push_back(0);
  arr.push_back((1e9)+10);
  sort(arr.begin(),arr.end());
  sum=0;
  res.push_back(sum);
  for(int i=1;i<(int)arr.size()-1;i++){
    idx=mp[arr[i]];
    sum+=cnt[idx];
    res.push_back(sum);
  }
  res.push_back(sum);
  sz=res.size();
  int pa=0,pq=0;
  sum=0;
  char win;

  while(pq<(int)q.size()){
    if(arr[pa]<q[pq].first)
      pa++;
    else if(arr[pa]==q[pq].first){
      idx=q[pq].second;
      win=person[idx];
      if(symbol[idx]=='<'){
        sum=res[pa-1];
      }
      else if(symbol[idx]=='>'){
        sum=res[sz-1]-res[pa];
      }
      else{
        sum=cnt[mp[arr[pa]]];
      }
      if(!(sum&1))
        win=(win=='C')?'D':'C';
      ret[idx]=win;
      pq++;
    }
    else{
      idx=q[pq].second;
      win=person[idx];
      if(symbol[idx]=='<'){
        sum=res[pa-1];
      }
      else if(symbol[idx]=='>'){
        sum=res[sz-1]-res[pa-1];
      }
      else{
        sum=0;
      }
      if(!(sum&1))
        win=(win=='C')?'D':'C';
      ret[idx]=win;
      pq++;
    }
  }
  for(int i=0;i<(int)ret.size();i++){
    printf("%c",ret[i]);
  }
  printf("\n");
  return 0;
}