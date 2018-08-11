#include <iostream>
#include <stdio.h>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

vector<int> arr;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
    	bitset<250009> found;
		vector<int> dp;
		int sum=0;
        arr.clear();
        int n;
        scanf("%d",&n);
        dp.push_back(0);
        found.set(0);
        for(int i=0;i<=n;i++){
            int temp;
            char ch;
            cin>>temp;
            if(i!=n)
            	cin>>ch;
            sum+=temp;
            arr.push_back(temp);
        }
        for(int i=0;i<n;i++){
            int sz=dp.size();
            for(int j=0;j<sz;j++){
                if(!found.test(arr[i]+dp[j])){
                    dp.push_back(arr[i]+dp[j]);
                    found.set(arr[i]+dp[j]);
                }
            }
        }
        int res=1e9;
        for(int i=1;i<(int)dp.size();i++)
            res=min(res,abs(sum-2*dp[i]));
        printf("%d\n",res);
    }
    return 0;
}
