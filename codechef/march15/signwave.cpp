#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    int t,s,c,k;
    cin>>t;
    long long int res;
    while(t--){
        res=1;
        cin>>s>>c>>k;
        if(s<c and k==1){
            res=res<<(c+1);
            res-=2;
            if(s>0)
                res+=3;
        }
        else{
            res=res<<(s-k+1);
            if(s-c<k)
                res=res<<1;
            res++;
            if(k>s)
                res=0;
        }
        cout<<res<<"\n";
    }
    return 0;

    //long double res;
    long double point;
    for(int S=0;S<=10;S++){
        for(int C=0;C<=10;C++){
            long double res;
            map<long double,int> X;
            int s=S,c=C;
            res=2;
            while(s--){
                res/=2;
                point=0;
                while(point<=2){
                    X[point]++;
                    point+=res;
                }
            }
            res=2;
            while(c--){
                res/=2;
                point=res/2;
                while(point<=2){
                    X[point]++;
                    point+=res;
                }
            }
            for(int k=1;k<20;k++){
                int cnt=0;
                for(map<long double,int>::iterator it=X.begin();it!=X.end();it++){
                    if(it->second>=k)
                        cnt++;
                }
                s=S,c=C;
                //cout<<S<<" "<<C<<" "<<k<<" "<<cnt<<" ";
                long long int ans=1;
                if(S<C and k==1){
                    ans=ans<<(c+1);
                    ans-=2;
                    if(s>0)
                        ans+=3;
                }
                else{
                    ans=ans<<(s-k+1);
                    if(s-c<k)
                        ans=ans<<1;
                    ans++;
                    if(k>s)
                        ans=0;
                }
                //cout<<ans<<" "<<(ans==cnt)<<" ";
                //if(ans!=cnt)
                    cout<<S<<" "<<C<<" "<<k<<" "<<cnt<<" "<<ans<<"\n";
                
                //cout<<"\n";
            }
        }
    }
    return 0;
}
