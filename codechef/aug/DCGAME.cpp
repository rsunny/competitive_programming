#include <iostream>
#include <stack>
#include <cstdio>
#include <unordered_map>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define rof(i,a,b) for(int (i)=(a);(i) > (b); --(i))
#define mp make_pair

const int maxn = 1e6 + 100;

int a[maxn], n, m, l[maxn], r[maxn], ans[maxn];
stack<int> s;
vector<int> arr,q;
unordered_map<int,unordered_map<int,int> > vis;
unordered_map<int,long long int> cnt;
unordered_map<int,unordered_map<int,vector<int> > >grp;
unordered_map<int,int> vis_q;
vector<char> symbols[1000100],person[1000100];
vector<int> idx[1000100];

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
  long long int sum,left,right,sz,pos,tot_sum=0;
  int num;
  char sym,per;

  scanf("%d %d", &n,&m);
  For(i,0,n)
    scanf("%d", a + i),a[i]*=-1;
  
  fill(l, l + maxn, -1);
  fill(r, r + maxn, n);
  find_range();

  // For(i,0,n){
  //   a[i]*=-1;
  //   left =l[i]+1;
  //   right=r[i]-1;
  //   if(!vis[left][right]){
  //     vis[left][right]=1;
  //     sum=(right-left+1LL)*(right-left+2LL); sum/=2LL;
  //     cnt[a[i]]+=sum;
  //   }
  //   grp[left][right].push_back(i);
  // }

  // for(int i=0;i<n;i++){
  //   left=l[i]+1;
  //   right=r[i]-1;
  //   if(vis[left][right]==1){
  //     vis[left][right]=2;
  //     sz=grp[left][right].size();
  //     pos=grp[left][right][0];
  //     sum=(pos-left)*(pos-left+1LL); sum/=2LL;
  //     cnt[a[i]]-=sum;
  //     for(int j=1;j<sz;j++){
  //       int prev=pos;
  //       pos=grp[left][right][j];
  //       sum=(pos-prev-1LL)*(pos-prev); sum/=2LL;
  //       cnt[a[i]]-=sum;
  //     }
  //     pos=grp[left][right][sz-1];
  //     sum=(right-pos)*(right-pos+1LL); sum/=2LL;
  //     cnt[a[i]]-=sum;
  //     tot_sum+=cnt[a[i]];
  //   }
  // }

  arr.push_back(a[0]);
  for(int i=1;i<n;i++){
    if(a[i]!=a[i-1]){
      arr.push_back(a[i]);
    } 
  }
  arr.push_back(0);
  arr.push_back((1e9)+1);
  sort(arr.begin(),arr.end());

  // while(m--){
  //   getchar();
  //   scanf("%c %d %c",&sym,&num,&per);
  //   char win=per;
  //   char loose=(per=='D')?'C':'D';
  //   if(sym=='<'){
  //     idx=lower_bound(arr.begin(), arr.end(),num)-arr.begin();idx--;
  //     sum=res[idx];
  //   }
  //   else if(sym=='>'){
  //     idx=upper_bound(arr.begin(), arr.end(),num)-arr.begin();idx--;
  //     sum=res[(int)res.size()-1]-res[idx];
  //   }
  //   else{
  //     idx=lower_bound(arr.begin(), arr.end(),num)-arr.begin();
  //     sum=0;
  //     if(arr[idx]==num)
  //       sum=res[idx]-res[idx-1];
  //   }
  //   if(sum&1)
  //     printf("%c",win);
  //   else
  //     printf("%c",loose);
  // }
  int x=0;
  int assign=1;
  string ret="";
  while(m--){
    ret+=" ";
    getchar();
    scanf("%c %d %c",&sym,&num,&per);
    if(!vis_q[num])
      vis_q[num]=assign,q.push_back(num),assign++;
    symbols[vis_q[num]].push_back(sym);
    person[vis_q[num]].push_back(per);
    idx[vis_q[num]].push_back(x);
    x++; 
  }

  sort(q.begin(), q.end());
  int point_arr=0;int point_q=0;
  sum=0;
  while(point_q<(int)q.size()){
    if(arr[point_arr]<q[point_q])
      sum+=cnt[arr[point_arr]] ,point_arr++;
    else{
      num=q[point_q];
      int sz=symbols[vis_q[num]].size();
      for(int i=0;i<sz;i++){
        if(symbols[vis_q[num]][i]=='<'){
          if(sum&1LL)
            ret[idx[vis_q[num]][i]]=person[vis_q[num]][i];
          else
            ret[idx[vis_q[num]][i]]=(person[vis_q[num]][i]=='D')?'C':'D';
        }
        else if(symbols[vis_q[num]][i]=='>'){
          if((tot_sum-sum-cnt[num])&1LL)
            ret[idx[vis_q[num]][i]]=person[vis_q[num]][i];
          else
            ret[idx[vis_q[num]][i]]=(person[vis_q[num]][i]=='D')?'C':'D';
        }
        else{
          if(cnt[num]&1LL)
            ret[idx[vis_q[num]][i]]=person[vis_q[num]][i];
          else
            ret[idx[vis_q[num]][i]]=(person[vis_q[num]][i]=='D')?'C':'D';
        }
      }
      point_q++;
    }
  }
  for(int i=0;i<(int)ret.size();i++)
    printf("%c",ret[i]);
  printf("\n");
  return 0;
}
