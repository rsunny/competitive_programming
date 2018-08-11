#include <bits/stdc++.h>

#define N 100000

using namespace std;

int v[N+1];

/*
 * Complete the function below.
 */
long game(vector <int> arr) {

    int n,i;
    long long s;

    n=arr.size();
    for(i=1;i<=n;i++)
        v[i]=arr[i-1];

    sort(v+1,v+n+1);
    s=v[n];
    for(i=n-1;i>0 &&v[i]>=0;i--)
        s+=v[i];

    for(i=2;i<=n &&v[i]<0;i+=2)
        s+=v[i];

    return s;
}

int main(){

    long res;
    int arr_size = 0;
    cin >> arr_size;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    vector<int> arr;
    for(int i = 0; i < arr_size; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        arr.push_back(arr_item);
    }

    res = game(arr);
    cout << res;

    return 0;
}
