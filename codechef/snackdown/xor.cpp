#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;
 
int inp[100005];
int arr[100005];
int rev[100005];

int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        memset(arr,0,sizeof arr);
        memset(rev,0,sizeof rev);
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>inp[i];
            arr[i]=inp[i]^arr[i-1];
        }
        for(int i=n;i>=1;i--)
            rev[i]=rev[i+1]^inp[i];
        int res=0;
        for(int i=1;i<=n;i++){
            if((arr[i-1]^rev[i+1])==0)
                res++;
        }
        cout<<res<<"\n";
    }
    return 0;
}

