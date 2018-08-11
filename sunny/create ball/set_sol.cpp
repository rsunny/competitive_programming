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

#include <assert.h>

/*
 * Complete the function below.
 */

double Djk(const vector<vector<double>>& distance, int start, int finish) {
    int n = (int)distance.size();

    vector<double> min_answer(distance.size(), 1e8);
    min_answer[start] = 0;

    vector<bool> selected(distance.size(), false);

    while (not selected[finish]) {
        double mn = 1e9;
        int index = -1;

        for (int itr = 0; itr < n; itr += 1) {
            if (selected[itr]) {
                continue;
            }
            if (min_answer[itr] < mn) {
                mn = min_answer[itr];
                index = itr;
            }
        }

        selected[index] = true;

        for (int itr = 0; itr < n; itr += 1) {
            auto cost = max(min_answer[index], distance[index][itr]);
            if (cost < min_answer[itr]) {
                min_answer[itr] = cost;
            }
        }
    }

    return min_answer[finish];
}

double Distance(pair<int, int> a, pair<int, int> b) {
    return sqrt(1.0 * (a.first - b.first) * (a.first - b.first) 
            + 1.0 * (a.second - b.second) * (a.second - b.second));
}

double Solve(const vector<pair<int, int>>& coordinates, int h) {
    int num_points = (int)coordinates.size();
    vector<vector<double>> distance(num_points + 2, vector<double>(num_points + 2));

    for (int i = 0; i < num_points; i += 1) {
        for (int j = 0; j < num_points; j += 1) {
            distance[i][j] = Distance(coordinates[i], coordinates[j]);
        }

        distance[i][num_points] = Distance(coordinates[i], {coordinates[i].first, 0});
        distance[i][num_points + 1] = Distance(coordinates[i], {coordinates[i].first, h});

        distance[num_points][i] = distance[i][num_points];
        distance[num_points + 1][i] = distance[i][num_points + 1];
    }

    distance[num_points][num_points + 1] = h;
    distance[num_points + 1][num_points] = h;
    
    return Djk(distance, num_points, num_points + 1);    
}


int create_ball(int n, int m, vector < int > x, vector < int > y) {
    int w, h, num_points; 
    w = n;
    h = m;
    num_points = x.size();
    assert(1 <= w and w <= 5000);
    assert(1 <= h and h <= 5000);
    assert(1 <= num_points and num_points <= 1000);

    vector<pair<int, int>> coordinates;

    for (int i = 0; i < num_points; i ++ ) {
        assert(1 <= x[i]);
        assert(x[i] < w);
        assert(1 <= y[i]);
        assert(y[i] < h);
        
        coordinates.push_back({x[i], y[i]});
    }

    double res = Solve(coordinates, h);
    // cout<<res<<"\n";
    return res;
}

int main() {
    int res;
    int _n;
    cin >> _n;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    int _m;
    cin >> _m;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    
    
    int _x_size = 0;
    cin >> _x_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _x;
    int _x_item;
    for(int _x_i=0; _x_i<_x_size; _x_i++) {
        cin >> _x_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _x.push_back(_x_item);
    }
    
    
    int _y_size = 0;
    cin >> _y_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _y;
    int _y_item;
    for(int _y_i=0; _y_i<_y_size; _y_i++) {
        cin >> _y_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _y.push_back(_y_item);
    }
    
    res = create_ball(_n, _m, _x, _y);
    cout << res << endl;
    
    return 0;
}
