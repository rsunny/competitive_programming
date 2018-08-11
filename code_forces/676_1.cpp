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

vector<int> aa,ab,ba,bb,A,B;

int main() {
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int a=0;
    int b=0;
    for(int i=0;i<n;i++){
        if(i==0){
            a=(s[i]=='a');
            b=(s[i]=='b');
            continue;
        }
        if(s[i-1]=='a' and s[i]=='a')
            a++;
        if(s[i-1]=='a' and s[i]=='b')
            A.push_back(a),B.push_back(0),a=0,b++;
        if(s[i-1]=='b' and s[i]=='b')
            b++;
        if(s[i-1]=='b' and s[i]=='a')
            B.push_back(b),A.push_back(0),b=0,a++;
    }
    A.push_back(a),B.push_back(b);
    A.push_back(0),B.push_back(0);
    n=A.size();
    for(int i=0;i<n;i+=2){
        if(i+1<n){
            aa.push_back(A[i]+B[i]);
            ab.push_back(A[i+1]+B[i+1]);
        }
    }
    n=aa.size();
    int i=0,j=0;
    int kk=k;
    int tot=0;
    while(j<n){
        if(kk){
            tot+=aa[j];
        }
        else{

        }
    }
    return 0;
}



