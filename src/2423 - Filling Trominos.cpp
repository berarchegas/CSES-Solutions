// Filling Trominos
//
// Problem name: Filling Trominos
// Problem Link: https://cses.fi/problemset/task/2423
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
 
using namespace std;
 
int v[105][105];
string impar[] = {
	"ABBAA",
	"AABAB",
	"BBABB",
	"ABAAC",
	"AABCC",
	"CBBDD",
	"CCAAD",
	"ABBAC",
	"AABCC"
};
 
void even(int x, int y, int n, int m) {
	for (int i = x; i < n; i += 3) {
		for (int j = y; j < m; j += 2) {
			
			// preencher um 3x2
			set<int> st;
			st.insert(v[i - 1][j]);
			st.insert(v[i - 1][j + 1]);
			st.insert(v[i][j - 1]);
			st.insert(v[i + 1][j - 1]);
			int cor;
			for (int k = 0; k <= 4; k++) {
				if (st.count(k) == 0) {
					cor = k;
					break;
				}
			}
			v[i][j] = v[i + 1][j] = v[i][j + 1] = cor;
			st.clear();
			st.insert(cor);
			st.insert(v[i + 2][j - 1]);
			for (int k = 0; k <= 2; k++) {
				if (st.count(k) == 0) {
					cor = k;
					break;
				}
			}
			v[i + 2][j] = v[i + 1][j + 1] = v[i + 2][j + 1] = cor;
		}
	}
}
 
void odd(int x, int j, int n, int m) {
	for (int i = x; i < n; i += 2) {
		set<int> st;
		st.insert(v[i - 1][j]);
		st.insert(v[i - 1][j + 1]);
		st.insert(v[i][j - 1]);
		st.insert(v[i + 1][j - 1]);
		int cor;
		for (int k = 0; k <= 4; k++) {
			if (st.count(k) == 0) {
				cor = k;
				break;
			}
		}
		v[i][j] = v[i + 1][j] = v[i][j + 1] = cor;
		st.clear();
		st.insert(cor);
		st.insert(v[i - 1][j + 2]);
		for (int k = 0; k <= 2; k++) {
			if (st.count(k) == 0) {
				cor = k;
				break;
			}
		}
		v[i][j + 2] = v[i + 1][j + 1] = v[i + 1][j + 2] = cor;
	}
	even(x, j + 3, n, m);
}
 
void oodd(int x, int y, int n, int m) {
	for (int i = x; i < x + 9; i++) {
		for (int j = y; j < y + 5; j++) v[i][j] = impar[i - x][j - y] - 'A';
	}
	odd(x + 9, y, n, y + 5);
	even(x, y + 5, n, m);
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		bool sw = false, ok = false;
		if (n % 3 != 0) {
			swap(n, m);
			sw = true;
		}
		if (n % 3 != 0 || min(n, m) < 2) cout << "NO\n";
		else if (m % 2 == 0) {
			// m par e n par ou impar
			
			ok = true;
			even(1, 1, n + 1, m + 1);
 
		}
		else if (n % 2 == 0) {
			// n par e m impar
			
			ok = true;	
			odd(1, 1, n + 1, m + 1);
		}
		else {
			// ambos impares
			
			if (n < 9 || m < 5) cout << "NO\n";
			else {
				ok = true;
				oodd(1, 1, n + 1, m + 1);
			}
		}
		if (ok) {
			cout << "YES\n";
			if (sw) {
				for (int i = 1; i <= m; i++) {
					for (int j = 1; j <= n; j++) cout << char('A' + v[j][i]);
					cout << '\n';
				}
			}
			else {
				for (int i = 1; i <= n; i++) {
					for (int j = 1; j <= m; j++) cout << char('A' + v[i][j]);
					cout << '\n';
				}
			}
		}
	}
    return 0;
}