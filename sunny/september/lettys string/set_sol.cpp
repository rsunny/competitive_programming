//http://codeforces.com/gym/100247/problem/H
#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */
int minOpe(int n, string initial, string target) {
    string s,t;
    s = initial;
    t = target;
    int ans=0, a=0;

    for(int i =0; i < n; i++) {
        if(s[i] != t[i]) a++;
        else if(a > 0) {
            a =0;
            ans++;
        }
    }
    
    if(a > 0) ans++;
    return ans;
}

int main(){
    int res;
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string initial;
    getline(cin, initial);

    string target;
    getline(cin, target);

    res = minOpe(n, initial, target);
    cout << res << endl;

    return 0;
}
