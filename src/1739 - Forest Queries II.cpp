/*
Problem Name: Forest Queries II
Problem Link: https://cses.fi/problemset/task/1739
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 1010
#define INF 1e17
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int M = 998244353;
 
int bit[MAXN][MAXN];
char m[MAXN][MAXN];
 
void upd(int x, int y, int val) {
	for (int i = x; i < MAXN; i += (i & -i)) {
		for (int j = y; j < MAXN; j += (j & -j)) bit[i][j] += val;
	}
}
 
int sum(int x, int y) {
	int resp = 0;
	for (int i = x; i > 0; i -= (i & -i)) {
		for (int j = y; j > 0; j -= (j & -j)) resp += bit[i][j];
	}
	return resp;
}
 
int main () { _
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> m[i][j];
			if (m[i][j] == '*') upd(i, j, 1);
		}
	}
	int tipo, x1, x2, y1, y2;
	for (int i = 0; i < q; i++) {
		cin >> tipo;
		if (tipo == 1) {
			cin >> x1 >> y1;
			if (m[x1][y1] == '*') {
				upd(x1, y1, -1);
				m[x1][y1] = '.';
			}
			else {
				upd(x1, y1, 1);
				m[x1][y1] = '*';
			}
		}
		else {
			cin >> x1 >> y1 >> x2 >> y2;
			cout << sum(x2, y2) + sum(x1-1, y1-1) - sum(x2, y1-1) - sum(x1-1, y2) << '\n';
		}
	}
	return 0;
}