#include <iostream>
#include <vector>
#include <stdio.h>
#include <cassert>
#include <algorithm>

using namespace std;
typedef long long LL;

LL ans;
int n;
int v[100009];
inline int lowbit(int x){
    return x&(-x);
}

void add(int x,int y){
    for (int i=x;i<=100001;i+=lowbit(i))
        v[i]+=y;
}

int get(int x){
    int res=0;
    for (int i=x;i;i-=lowbit(i))
        res+=v[i];
    return res;
}

struct node{
    int x,id;
}a[1009];

vector<node> q[100009]; 
int b[100009],nn;

long sortArr(vector<int> arr) {
    n = arr.size();
    assert( n >=1 );
    assert( n <= 1000 );
    for (int i=1;i<=n;i++){
        assert(arr[i-1] >= 1 and arr[i-1] <= 100000);
        arr[i - 1] = (-1 * arr[i-1]) + 100001;
        assert(arr[i-1] >= 1 and arr[i-1] <= 100000);
        a[i].x = arr[i - 1];
        a[i].id=i;
        q[a[i].x].push_back(a[i]);
        add(i,1);
    }

    int now=0;
    
    for (int i=1;i<=100000;i++){
        if (q[i].size()==0) continue;
        nn=0;
        int flag=0;
        for (int j=0;j<q[i].size();j++)
            if (q[i][j].id>now) b[++nn]=q[i][j].id;
        for (int j=0;j<q[i].size();j++)
            if (q[i][j].id<now) b[++nn]=q[i][j].id,flag=1;
        if (flag==0) ans+=(LL)(get(b[nn])-get(now));
        else ans+=(LL)(get(n)-get(now))+(LL)(get(b[nn]));
        now=b[nn];
        for (int j=0;j<q[i].size();j++)
            add(q[i][j].id,-1);
    }
    return ans;
}

int main(){
    int arr_count;
    cin >> arr_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(arr_count);

    for (int arr_itr = 0; arr_itr < arr_count; arr_itr++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[arr_itr] = arr_item;
    }

    long res = sortArr(arr);

    cout << res << "\n";

    return 0;
}
