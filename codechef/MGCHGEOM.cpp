#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <utility>
#include <iostream>

using namespace std;

#define REMOVE_REDUNDANT

typedef double T;
const T EPS = 1e-7;
struct PT { 
  T x, y; 
  PT() {} 
  PT(T x, T y) : x(x), y(y) {}
  bool operator<(const PT &rhs) const { return make_pair(y,x) < make_pair(rhs.y,rhs.x); }
  bool operator==(const PT &rhs) const { return make_pair(y,x) == make_pair(rhs.y,rhs.x); }
};

T cross(PT p, PT q) { return p.x*q.y-p.y*q.x; }
T area2(PT a, PT b, PT c) { return cross(a,b) + cross(b,c) + cross(c,a); }

#ifdef REMOVE_REDUNDANT
  bool between(const PT &a, const PT &b, const PT &c) {
    return (fabs(area2(a,b,c)) < EPS && (a.x-b.x)*(c.x-b.x) <= 0 && (a.y-b.y)*(c.y-b.y) <= 0);
  }
#endif

void ConvexHull(vector<PT> &pts) {
  sort(pts.begin(), pts.end());
  pts.erase(unique(pts.begin(), pts.end()), pts.end());
  vector<PT> up, dn;
  for (int i = 0; i < pts.size(); i++) {
    while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
    while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
    up.push_back(pts[i]);
    dn.push_back(pts[i]);
  }
  pts = dn;
  for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
  
  #ifdef REMOVE_REDUNDANT
    if (pts.size() <= 2) return;
    dn.clear();
    dn.push_back(pts[0]);
    dn.push_back(pts[1]);
    for (int i = 2; i < pts.size(); i++) {
      if (between(dn[dn.size()-2], dn[dn.size()-1], pts[i])) dn.pop_back();
      dn.push_back(pts[i]);
    }
    if (dn.size() >= 3 && between(dn.back(), dn[0], dn[1])) {
      dn[0] = dn.back();
      dn.pop_back();
    }
    pts = dn;
  #endif
  return ;
}

int main() {
  int t;
  set<pair<int,int> > points;
  scanf("%d", &t);
  while(t--){
    int n,x,y;
    char op;
    points.clear();
    scanf("%d", &n);
    int a=0;
    vector<PT> v;
    for (int j = 0; j < n; j++){
      cin>>op;
      scanf("%d %d",&x,&y);
      PT tmp;
      
      if(op=='-'){
        points.erase(points.find(make_pair(x,y)));
        set<pair<int,int> > :: iterator it;
        a=0;
        v.clear();
        for(it=points.begin();it!=points.end();it++){
          v.push_back(tmp);
          v[a].x=(*it).first,v[a].y=(*it).second,a++;
          }
      }
      else{
        points.insert(make_pair(x,y));
        v.push_back(tmp);
        v[a].x=x,v[a].y=y,a++;
      }
      
      int N=points.size();
      vector<PT> h(v);

      ConvexHull(h);
      double tot=0;
      double temp1,temp2;
      N=h.size();

      for (int i = 0; i < N; i++){
        temp1=h[i].x*h[(i+1)%N].y;
        temp2=h[i].y*h[(i+1)%N].x;
        tot+=(temp1-temp2);
      }
      tot/=2;
      printf("%.1lf\n",tot);
    }
  }
  return 0;
}
