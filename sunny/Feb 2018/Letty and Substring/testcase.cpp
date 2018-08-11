#include <iostream>
#include <vector>
#include <stdio.h>
#include <cassert>
#include <algorithm>

using namespace std;

void change_test(vector<int> points, string strg) {
	for (int i = 0; i < min(10000, (int)strg.size()); i++) {
		strg[i] = 'a' + 8;
	}
	cout << 26 << "\n";
	for (int i = 0; i < 26; i++)
		cout << points[i] << "\n";
	cout << strg << "\n";
	return;
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

    change_test(points, strg);

    return 0;
}
