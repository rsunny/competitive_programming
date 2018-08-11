#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */
int alpha[26];

string maxDiff(vector <string> names) {
    string res="     ";
    int n=names.size();
    for(int i=0;i<5;i++){
        int mini=1e9;
        for(int j=0;j<n;j++){
            alpha[names[j][i]-'a']++;
        }
        for(int j=0;j<26;j++)
            mini=min(mini,alpha[j]);
        for(int j=0;j<26;j++){
            if(alpha[j]==mini)
                res[i]=('a'+j);
            alpha[j]=0;
        }
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string res;
    int names_size = 0;
    cin >> names_size;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    vector<string> names;
    for(int i = 0; i < names_size; i++) {
        string names_item;
        getline(cin, names_item);
        names.push_back(names_item);
    }

    res = maxDiff(names);
    cout << res << endl;

    return 0;
}
