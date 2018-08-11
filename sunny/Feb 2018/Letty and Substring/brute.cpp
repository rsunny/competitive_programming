#include <iostream>
#include <vector>
#include <stdio.h>
#include <cassert>
#include <algorithm>

using namespace std;

// vector<int> dp[27];
// int cum[1000009];

// int findMax(vector<int> points, string strg) {
//     strg = " " + strg;
//     int n = strg.size();
//     for(int i=1;i<n;i++){
//         int ind = strg[i] - 'a';
//         cum[i] = (cum[i-1] + points[ind]);
//         dp[ind].push_back(i);
//     }
//     int res = -1e9;
//     int a=-1,b=-1;
//     for(int i=0;i<26;i++){
//         for(int j=0;j<dp[i].size();j++){
//             for(int k=j;k<dp[i].size();k++){
//                 if(cum[dp[i][k]] - cum[dp[i][j] - 1] > res){
//                     res = cum[dp[i][k]] - cum[dp[i][j] - 1];
//                     a = dp[i][j];
//                     b = dp[i][k];
//                 }
//             }
//         }
//     }
//     cout << a << " " << b << "\n";
//     return res;
// }

vector <int> indices[26];
vector <int> score((int)1e6 + 10, 0);

int find_best_match() {
    int ans = -1e8;
    for(int i = 0; i < 26; i++) {
        int left_ptr = 0;
        //cout << i << " chk \n";
        for(int j = 1; j < (int)indices[i].size(); j++) {
            //cout << indices[i][left_ptr] << " " << score[indices[i][left_ptr]] << endl;
            int left_score = indices[i][left_ptr] > 0 ? score[indices[i][left_ptr] - 1] : 0;
            if(score[indices[i][j]] - left_score < 0) {
                left_ptr = j;
            }
            else {
                ans = max(ans, score[indices[i][j]] - left_score);
            }
        }
    }
    
    return ans;
}   

int findMax(vector<int> points, string strg) {
    /*
     * Write your code here.
     */
    
    score[0] = points[(int)(strg[0] - 'a')];
    indices[(int)(strg[0] - 'a')].push_back(0);
    for(int i = 1; i < strg.size(); i++) {
        score[i] = score[i - 1] + points[(int)(strg[i] - 'a')];
        indices[(int)(strg[i] - 'a')].push_back(i);
    }
    // for(int i = 0; i < 26; i++) {
    //     for(int j = 0; j < indices[i].size(); j++) {
    //         cout << indices[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    int ans = find_best_match();
    for(int i = 0; i < 26; i++) {
        if(indices[i].size() > 0) {
            ans = max(ans, points[i]);
        }
    }
    return ans;
}

int main(){
    int points_count;
    cin >> points_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> points(points_count);

    for (int points_itr = 0; points_itr < points_count; points_itr++) {
        int points_item;
        cin >> points_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        points[points_itr] = points_item;
    }

    string strg;
    getline(cin, strg);

    int res = findMax(points, strg);

    cout << res << "\n";

    return 0;
}
