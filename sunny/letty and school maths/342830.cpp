#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */

#define SIZE 6005

typedef long long int ll;
typedef pair <int,int> P;

P pos[SIZE];
vector <P> nd;
vector <int> all,query;

int calCost(vector < int > x1, vector < int > x2, int m) {
    int n,K;
    n=x1.size();
    K = m;
    assert(x1.size()==x2.size());
    assert(n>=1 and n<=1000);
    assert(m>=1 and m<=n);
    
    for(int i=0;i<n;i++){
        int x,y;
        x = x1[i];
        y = x2[i];
        assert(x>=1 and x<=y and y<=100000);
        pos[i]=P(x,y);
        all.push_back(y-x);
    }
    
    sort(all.begin(),all.end());
    ll ret=0;
    
    for(int i=0;i<min(K-1,(int) all.size());i++) ret+=all[all.size()-i-1];
    
    sort(pos,pos+n);
    for(int i=0;i<n;i++)
    {
        while(!nd.empty()&&nd[nd.size()-1].second>=pos[i].second)
        {
            P p=nd[nd.size()-1];nd.pop_back();
            query.push_back(p.second-p.first);
        }
        nd.push_back(pos[i]);
    }
    ll now=nd[0].second-nd[nd.size()-1].first;
    for(int i=0;i+1<(int)nd.size();i++) 
        query.push_back(-nd[i].first+nd[i+1].second);
    sort(query.begin(),query.end());
    for(int i=0;i<min(K-1,(int) query.size());i++) 
        now+=query[query.size()-i-1];
    return max(ret,now);
}

int main() {
    int res;
    
    int _x1_size = 0;
    cin >> _x1_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _x1;
    int _x1_item;
    for(int _x1_i=0; _x1_i<_x1_size; _x1_i++) {
        cin >> _x1_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _x1.push_back(_x1_item);
    }
    
    
    int _x2_size = 0;
    cin >> _x2_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _x2;
    int _x2_item;
    for(int _x2_i=0; _x2_i<_x2_size; _x2_i++) {
        cin >> _x2_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _x2.push_back(_x2_item);
    }
    
    int _m;
    cin >> _m;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    res = calCost(_x1, _x2, _m);
    cout << res << endl;
    
    return 0;
}
