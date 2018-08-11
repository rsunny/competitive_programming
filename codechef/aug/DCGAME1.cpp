#include <iostream>
#include <stack>
#include <cstdio>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define rof(i,a,b) for(int (i)=(a);(i) > (b); --(i))

const int maxn = 1e6 + 100;

struct trie {
  trie *next[10];
  int assign;
  trie() {
    for(int i=0; i<10; i++) next[i] = NULL;
    assign = 0;
  }
};

trie *head,*tail;
bool vis1[maxn];
int a[maxn], n, m, l[maxn], r[maxn], ans[maxn];
stack<int> s;
unordered_map<int,int> mp;
vector<int> arr;
vector<int> pos[maxn];
long long int cnt[maxn];
vector<long long int> res;
int assign1;

int ass(int num,bool a){
  tail=head;
  while(num) {
    int n=num%10;
    if(tail->next[n]==NULL) tail->next[n] = new trie;
    tail = tail->next[n];
    num/=10;
  }
  if(a)
    return tail->assign;
  if(!tail->assign)
    tail->assign=assign1++;
  return tail->assign;
}

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

  scanf("%d %d", &n,&m);
  For(i,0,n)
    scanf("%d", a + i),a[i]*=-1;

  fill(l, l + maxn, -1);
  fill(r, r + maxn, n);
  find_range();
  
  assign1=1;
  assign=1;
  
  for(int i=0;i<n;i++){
    a[i]*=-1;
    int idx1=ass(a[i],false);
    if(!mp[a[i]]){
      mp[a[i]]=assign;
      assign++;
      arr.push_back(a[i]);
    }
    assert(idx1==mp[a[i]]);
    pos[mp[a[i]]].push_back(i);
  }

  for(int i=0;i<(int)arr.size();i++){
    idx=mp[arr[i]];
    int idx1=ass(arr[i],false);
    assert(idx==idx1);
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
    int idx1=ass(arr[i],false);
    assert(idx==idx1);
    sum+=cnt[idx];
    res.push_back(sum);
  }
  res.push_back(sum);

  while(m--){
    getchar();
    scanf("%c %d %c",&sym,&num,&per);
    char win=per;
    char loose=(per=='D')?'C':'D';
    if(sym=='<'){
      idx=lower_bound(arr.begin(), arr.end(),num)-arr.begin();idx--;
      sum=res[idx];
    }
    else if(sym=='>'){
      idx=upper_bound(arr.begin(), arr.end(),num)-arr.begin();idx--;
      sum=res[(int)res.size()-1]-res[idx];
    }
    else{
      sum=cnt[mp[num]];
    }
    if(sum&1)
      printf("%c",win);
    else
      printf("%c",loose);
  }
  return 0;
}