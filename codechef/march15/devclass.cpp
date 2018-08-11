#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


string s;

void zero(){
    int g=0,b=0;
    int n=s.size();
    for(int i=0;i<n;i++){
        g+=(s[i]=='G');
        b+=(s[i]=='B');
    }
    if(abs(b-g)>1){
        cout<<-1<<"\n";
        return ;
    }
    int res1=0,res2=0;
    for(int i=0;i<n;i++){
        if(i%2){
            res1+=(s[i]!='G');
            res2+=(s[i]!='B');
        }
        else{
            res1+=(s[i]!='B');
            res2+=(s[i]!='G');
        }
    }
    if(b>g)
        cout<<res1/2<<"\n";
    else if(g>b)
        cout<<res2/2<<"\n";
    else
        cout<<min(res1/2,res2/2)<<"\n";
    return ;
}

void one(){
    int g=0,b=0;
    int n=s.size();
    for(int i=0;i<n;i++){
        g+=(s[i]=='G');
        b+=(s[i]=='B');
    }
    if(abs(b-g)>1){
        cout<<-1<<"\n";
        return ;
    }
    vector<int> res1b,res1g,res2b,res2g;
    for(int i=0;i<n;i++){
        if(i%2){
            if(s[i]!='G')
                res1g.push_back(i);
            if(s[i]!='B')
                res2b.push_back(i);
        }
        else{
            if(s[i]!='B')
                res1b.push_back(i);
            if(s[i]!='G')
                res2g.push_back(i);
        }
    }
    int res1=0,res2=0;
    if(b>g){
        for(int i=0;i<res1b.size();i++)
            res1+=abs(res1b[i]-res1g[i]);
        cout<<res1<<"\n";
    }
    else if(g>b){
        for(int i=0;i<res2b.size();i++)
            res2+=abs(res2b[i]-res2g[i]);
        cout<<res2<<"\n";
    }
    else{
        for(int i=0;i<res1b.size();i++)
            res1+=abs(res1b[i]-res1g[i]);
        for(int i=0;i<res2b.size();i++)
            res2+=abs(res2b[i]-res2g[i]);
        cout<<min(res1,res2)<<"\n";
    }
    return ;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int test;
        cin>>test;
        cin>>s;
        if(test==0)
            zero();
        else
            one();
    }
    return 0;
}
