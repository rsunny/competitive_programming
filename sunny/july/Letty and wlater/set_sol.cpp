#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */

typedef long long int64;

void Answer(int letty_dolars) {
    cout << letty_dolars << '\n';
    exit(0);
}

int letty, walter;
int money;
int bonus_letty, bonus_walter;

int MoneyStatus(int letty_dolars) {
    int64 letty_final_power = letty + 1LL * letty_dolars * bonus_letty;
    int64 walter_final_power = walter + 1LL * (money - letty_dolars) * bonus_walter;

    // if we got a solution, just print it. no need to not do that
    if (letty_final_power == walter_final_power) {
        Answer(letty_dolars);
    }

    return letty_final_power < walter_final_power;
}

int finMax(int n, int m, int x, int y, int S) {
    long long a, s, k, x, y;
    a=n;
    s=m;
    k=S;

    int low=0;
    int high=k;
    while(low<hig){
        int mid=low+high;
        mid/=2;
        k=mid;
        double ans = (double)(s + k * y - a) / (x + y);
        if (int(ans) == ans && ans >= 0 && ans <= k) {
            cout << int(ans) << "\n";
        } else {
            cout << "-1\n";
        }
    }
    letty = n;
    walter = m;
    money = s;
    bonus_letty =x;
    bonus_walter = y;

    int letty_dolars = 0;
    int mx_letty_dolars = money;

    while (letty_dolars < mx_letty_dolars) {    
        int mid = (letty_dolars + mx_letty_dolars) / 2;
        if (MoneyStatus(mid)) {
            // too little letty
            letty_dolars = mid + 1;
        } else {
            // too much walter for 'mid'
            mx_letty_dolars = mid - 1;
        }
    }

    // just check again for letty_dolars
    MoneyStatus(letty_dolars);

    // no solution until now. print -1
    // if we found a solution until now, the program would've exited
    Answer(-1);
    
    return 0;
}

int main(){

    int res;
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int x;
    cin >> x;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int y;
    cin >> y;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int s;
    cin >> s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    res = finMax(n, m, x, y, s);
    cout << res << endl;

    return 0;
}
