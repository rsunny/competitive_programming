#include <bits/stdc++.h>

using namespace std;
 
#define FORN(i, n) for (int i = 0; i <  (int)(n); i++)
#define MOD 1000000007

int n, odd;
 
/*
 * Complete the function below.
 */
int count(vector <int> arr) {
 
  n=arr.size();
  odd = 0;
  
  FORN(i, n) {
    odd += arr[i];
  }
 
  long long int res=1;

  FORN(i, n-1) {
    res*=2;
    res%=MOD;
  }

  if (odd == 0) {
    res*=2;
    res%=MOD;
  }
  
  return res;
}

int main(){
    
    int res;
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

    res = count(arr);
    cout << res << endl;

    return 0;
}
