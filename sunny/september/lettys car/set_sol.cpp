#include <bits/stdc++.h>

using namespace std;


#include <assert.h>

/*
 * Complete the function below.
 */
int minTimes(int x, int y, int z) {
    int gas=z, res=0, d1=x-y, d2=y;
    int k=600;
    while(k--){
        if(gas<d1)
            return -1;
        gas-=d1;
        if((k==0 && gas<d2) || (k>0 && gas<2*d2))
            res++,gas=z;
        if(gas<d2)
            return -1;
        gas-=d2;
        swap(d1,d2);
    }
  return res;
}

int main()
{
    int res;
    int x;
    cin >> x;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int y;
    cin >> y;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int z;
    cin >> z;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    res = minTimes(x, y, z);
    cout << res << endl;

    return 0;
}
