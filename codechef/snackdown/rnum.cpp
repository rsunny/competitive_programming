#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;
 
vector<int> num,kill_max,kill_min;

int main(){
    int test;
    cin>>test;
    while(test--){
        int n,ele;
        num.clear();
        kill_min.clear();
        kill_max.clear();
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>ele;
            num.push_back(ele);
            kill_max.push_back(0);
            kill_min.push_back(0);
        }
        sort(num.begin(), num.end());
        int mini=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            if(kill_min[i]==0){
                if(i+1<n and num[i]+1==num[i+1]){
                    kill_min[i+1]=1;
                    kill_min[i]=1;mini++;
                    if(i+2<n and num[i]+2==num[i+2])
                        kill_min[i+2]=1;
                }
                else
                    kill_min[i]=1,mini++;
            }
            if(kill_max[i]==0){
                kill_max[i]=1;
                maxi++;
                if(i+1<n and num[i]+1==num[i+1])
                    kill_max[i+1]=1;
            }
        }
        cout<<mini<<" "<<maxi<<"\n";
    }
    return 0;
}

