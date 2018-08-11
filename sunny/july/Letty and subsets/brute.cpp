#include <bits/stdc++.h>

using namespace std;

int N,M;
set<vector<int> > res;
vector<int> temp,tmp;

void reco(int sum, int sz){
    if((sz==M and sum!=N) or sum>N)
        return ;
    if(sz==M and sum==N){
        tmp=temp;
        sort(tmp.begin(),tmp.end());
        res.insert(tmp);
        return;
    }
    for(int i=1;i<=N;i++){
        temp.push_back(i);
        reco(sum+i,sz+1);
        temp.pop_back();
    }
    return ;
}

int findXor(int n, int m) {
    N=n;
    M=m;
    reco(0,0);
    int ans=0;
    for(set<vector<int> > :: iterator it=res.begin();it!=res.end();it++){
        tmp=*it;
        for(int j=0;j<(int)tmp.size();j++){
            ans^=tmp[j];
            // cout<<tmp[j]<<" ";
        }
        // cout<<"\n";
    }
    return ans;
}

int main(){
    ofstream fout(getenv("OUTPUT_PATH"));

    int res;
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    res = findXor(n, m);
    cout << res << endl;

    return 0;
}
