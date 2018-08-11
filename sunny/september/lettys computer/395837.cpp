#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */
int alpha[26];

string minDiff(vector <string> names) {
    string res="     ";
    int n=names.size();
    for(int i=0;i<5;i++){
        int maxi=0;
        for(int j=0;j<n;j++){
            alpha[names[j][i]-'a']++;
            maxi=max(maxi,alpha[names[j][i]-'a']);
        }
        for(int j=0;j<26;j++){
            if(alpha[j]==maxi)
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

    res = minDiff(names);
    cout << res << endl;

    return 0;
}
