#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string.h>

using namespace std;

int t;
string s;

int main() {
    scanf("%d",&t);
    while(t--){
        cin>>s;
        int one=0,zero=0;
        for(int i=0;i<(int)s.size();i++)
            one+=(s[i]=='1'),zero+=(s[i]=='0');
        cout<<s.size()<<" "<<one<<" "<<zero<<"\n";
    }
    return 0;
}
