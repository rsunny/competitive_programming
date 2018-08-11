#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <sstream>
#include <map>
#include <unordered_map>

using namespace std;

int used[15];
map<long long int ,int> cc;
map<vector<int>,bool> dp;

int main(){
    int test;
    cin>>test;
    while(test){
        memset(used,-1,sizeof used);
        long long int res=0;
        string num;
        stringstream ss;
        ss<<test;ss>>num;
        // int mod;
        // cin>>num>>mod;
        int cnt=1;
        //cout<<num<<"       ";
        int nn=num[0]-'0';
        used[nn]=1;
        for(int i=0;i<(int)num.size();i++){
            nn=num[i]-'0';
            if(used[nn]==-1){
                if(cnt==1){
                    used[nn]=0;
                }
                else 
                    used[nn]=cnt;
                cnt++;
            }
            res=(res*10)+used[nn];
        }
        cc[res]++;
        test--;
        vector<int> v;
        for(int i=0;i<=9;i++)
            v.push_back(used[i]);
        dp[v]=true;
    }
    map<long long int, int> :: iterator it;
    for(it=cc.begin();it!=cc.end();it++)
        cout<<it->first<<" "<<it->second<<"\n";
    cout<<dp.size()<<"\n";
    return 0;
}
