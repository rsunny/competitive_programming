#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;

int x = 0, y = 0;
int k = -1;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;
	
	string s;
	cin >> s;

	int pay = 0;

	for(int i = 0 ; i < n ; i++){
		if(s[i] == 'U')
			++y;
		else
			++x;
		if(x < y and k == 0)
			pay++;
		else if(x > y and k == 1)
			pay++;
		if(x < y)
			k = 1;
		if(x > y)
			k = 0;
	}

	cout << pay << "\n";
	return 0;
}
