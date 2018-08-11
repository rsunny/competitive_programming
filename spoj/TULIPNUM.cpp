#include <iostream>
#include <unordered_map>
#include <stdio.h>

using namespace std;

int arr[100009];
int ans[100009];

int main(){
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++){
        int n,q,l,r;
        scanf("%d %d",&n,&q);
        for(int i=1;i<=n;i++){
            scanf("%d",&arr[i]);
            ans[i]=ans[i-1]+(arr[i]!=arr[i-1]);
        }
        printf("Case %d:\n",test);
        while(q--){
            scanf("%d %d",&l,&r);
            printf("%d\n",ans[r]-ans[l-1]+(ans[l]==ans[l-1]));
        }
    }
    return 0;
}