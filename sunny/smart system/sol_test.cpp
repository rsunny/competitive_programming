#include <bits/stdc++.h>

using namespace std;

#include <assert.h>

#define SZ(x) ((int)x.size())
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define clrall(name,val) memset(name,(val),sizeof(name))
#define psb(b) push_back((b))
#define ppb() pop_back()
#define oo (1<<30)
#define mp make_pair
#define fs first
#define sc second
#define ll long long int

enum{
   Manager = 0,
   Employee = 1
};

const int MAXN = 1000;
const int MAXV = 100000;

void isValid(int n,int m,vector<int> ma,vector<int> mr,vector<int> ea,vector<int> er){
   assert(n>=1&&n<=MAXN);
   assert(m>=1&&m<=MAXN);
   assert(SZ(ma)==n);
   assert(SZ(mr)==n);
   assert(SZ(ea)==m);
   assert(SZ(er)==m);
   for(auto i:ma) assert(i>=1&&i<=MAXV);
   for(auto i:mr) assert(i>=1&&i<=MAXV);
   for(auto i:ea) assert(i>=1&&i<=MAXV);
   for(auto i:er) assert(i>=1&&i<=MAXV);
   return ;
}

typedef pair<int,int> pii;

struct info
{
   int a,b,t;
   info(){}
   info(int a,int b,int t):a(a),b(b),t(t){}
   bool operator<(const info& x)const{
       return mp(mp(a,b),t)<mp(mp(x.a,x.b),x.t);
   }
};

map<info,int> dp;

vector<pii> man,emp;

vector<bool> eflag;

int getT(int id,int idx,int t){
   switch (id)
   {
   case Manager:

       if(man[idx].fs<t) t+=man[idx].sc;
       else t=man[idx].fs+man[idx].sc;
       break;
   case Employee:

       if(emp[idx].fs<t) t+=emp[idx].sc;
       else t=emp[idx].fs+emp[idx].sc;
       break;
   default:
       break;
   }
   return t;
}

int solve(int a,int b,int t){
   if(a==SZ(man)&&b==SZ(emp)) return t;
   info id=info(a,b,t);
   if(dp.count(info(id))) return dp[id];
   int ret=1<<30;
   dp[id]=ret;
   if(a<SZ(man)){
       ret=min(ret,solve(a+1,b,getT(Manager,a,t)));
   }
   if(b<SZ(emp)){
       int T=t;
       for(int i=b;i<SZ(emp);i++){
           if(eflag[i]) continue;
           T=max(T,getT(Employee,i,t));
           if(a<SZ(man)){
               if((i<SZ(emp)-1 && max(T,getT(Employee,i+1,t))>=man[a].fs) || T>=man[a].fs)
                   ret=min(ret,solve(a+1,i+1,getT(Manager,a,T)));
           }
       }
       ret=min(ret,solve(a,SZ(emp),T));
   }
   dp[id]=ret;
   return ret;
}

long min_time(vector < int > ma, vector < int > mr, vector < int > ea, vector < int > er) {
  int n =ma.size();
  int m=ea.size();
  isValid(n, m, ma, mr, ea, er);
   for (int i=0;i<n;i++)
   {
       man.psb(mp(ma[i],mr[i]));
   }
   for (int i=0;i<m;i++)
   {
       emp.psb(mp(ea[i],er[i]));
   }
   sort(all(man));
   sort(all(emp));
   eflag.resize(m);
   int v=0;
   for(int i=m-1;i>=0;i--){
       eflag[i]=(emp[i].sc<=v);
       v=max(v,emp[i].sc);
   }
   return solve(0,0,0);
}

int main() {
    long res;
    
    int _m_arrive_size = 0;
    cin >> _m_arrive_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _m_arrive;
    int _m_arrive_item;
    for(int _m_arrive_i=0; _m_arrive_i<_m_arrive_size; _m_arrive_i++) {
        cin >> _m_arrive_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _m_arrive.push_back(_m_arrive_item);
    }
    
    
    int _m_req_size = 0;
    cin >> _m_req_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _m_req;
    int _m_req_item;
    for(int _m_req_i=0; _m_req_i<_m_req_size; _m_req_i++) {
        cin >> _m_req_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _m_req.push_back(_m_req_item);
    }
    
    
    int _e_arrive_size = 0;
    cin >> _e_arrive_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _e_arrive;
    int _e_arrive_item;
    for(int _e_arrive_i=0; _e_arrive_i<_e_arrive_size; _e_arrive_i++) {
        cin >> _e_arrive_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _e_arrive.push_back(_e_arrive_item);
    }
    
    
    int _e_req_size = 0;
    cin >> _e_req_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _e_req;
    int _e_req_item;
    for(int _e_req_i=0; _e_req_i<_e_req_size; _e_req_i++) {
        cin >> _e_req_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _e_req.push_back(_e_req_item);
    }
    
    res = min_time(_m_arrive, _m_req, _e_arrive, _e_req);
    cout << res;
    
    return 0;
}

