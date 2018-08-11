#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int arr[105];

int main() {
    int n;
    int res=0;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            swap(arr[i],arr[j]);
            int I,J;
            for(int l=0;l<n;l++){
                if(arr[l]==1)
                    I=l;
                if(arr[l]==n)
                    J=l;
            }
            res=max(res,abs(I-J));
            swap(arr[i],arr[j]);
        }
    }
    cout<<res<<"\n";
    return 0;
}



