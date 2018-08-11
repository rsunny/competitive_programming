#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;

int board[4][100][100];
int n;
int ord[] = {0, 1, 2, 3};
int act_board[2][209][209];
int set_board[209][209];

int check(int ptr) {
	int ans = 0;
	for (int i = 0; i < 2 * n; ++i) {
		for (int j = 0; j < 2 * n; ++j) {
			ans += (set_board[i][j] != act_board[ptr][i][j]);
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	
	for (int k = 0; k < 4; ++k) {
		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			for (int j = 0; j < n; ++j) {
				board[k][i][j] = s[j] - '0';
			}
		}
	}

	int v1 = 1;
	int v2 = 0;
	for (int i = 0; i < 2 * n; ++i) {
		int val1 = v1;
		int val2 = v2;
		for (int j = 0; j < 2 * n; ++j) {
			act_board[0][i][j] = val1;
			act_board[1][i][j] = val2;
			val1 ^= 1;
			val2 ^= 1;
		}
		v1 ^= 1;
		v2 ^= 1;
	}

	int res = 1e9;
	
	do{
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				set_board[i][j] = board[ord[0]][i][j];
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = n; j < 2 * n; ++j) {
				set_board[i][j] = board[ord[1]][i][j - n];
			}
		}
		for (int i = n; i < 2 * n; ++i) {
			for (int j = 0; j < n; ++j) {
				set_board[i][j] = board[ord[2]][i - n][j];
			}
		}
		for (int i = n; i < 2 * n; ++i) {
			for (int j = n; j < 2 * n; ++j) {
				set_board[i][j] = board[ord[3]][i - n][j - n];
			}
		}
		
		res = min(res,check(0));
		res = min(res,check(1));
	}while(next_permutation(ord, ord + 4));
	
	cout << res << "\n";

	return 0;
}
