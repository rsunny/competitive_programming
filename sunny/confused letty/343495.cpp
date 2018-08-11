#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */

vector<int> x,y;

int findCells(int n, int x1, int y1, int x2, int y2) {
    assert(n>0 and n<=1000);
    x.push_back(x1);
    x.push_back(x2);
    y.push_back(y1);
    y.push_back(y2);
    for(int i=0;i<2;i++){
        assert(x[i]>0 and x[i]<=n);
        assert(y[i]>0 and y[i]<=n);
    }
    int res=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            set<int> c;
            for(int k=0;k<2;k++){
                c.insert(abs(i-x[k])+abs(j-y[k]));
            }    
            if((int)c.size()==1)
                res++;
        }
    }
    return res;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));
    int res;
    int _n;
    cin >> _n;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    int _x1;
    cin >> _x1;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    int _y1;
    cin >> _y1;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    int _x2;
    cin >> _x2;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    int _y2;
    cin >> _y2;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    res = findCells(_n, _x1, _y1, _x2, _y2);
    cout << res << endl;
    
    return 0;
}
