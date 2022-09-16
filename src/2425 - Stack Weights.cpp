// Stack Weights
//
// Problem name: Stack Weights
// Problem Link: https://cses.fi/problemset/task/2425
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
    
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;
const ll INF = 2e18;
 
ll lz[4 * MAXN], a[2][4 * MAXN];
 
void push(int node, int i, int j) {
	a[0][node] += lz[node];
	a[1][node] += lz[node];
	if (i != j) {
		lz[2 * node] += lz[node];
		lz[2 * node + 1] += lz[node];
	}
	lz[node] = 0;
}
 
void upd(int node, int i, int j, int ini, int fim, int val) {
	push(node, i, j);
	if (ini <= i && j <= fim) {
		lz[node] += val;
		push(node, i, j);
	}
	else if (j < ini || i > fim) return;
	else {
		int m = (i + j) / 2;
		upd(2 * node, i, m, ini, fim, val);
		upd(2 * node + 1, m + 1, j, ini, fim, val);
		a[0][node] = min(a[0][2 * node], a[0][2 * node + 1]);
		a[1][node] = max(a[1][2 * node], a[1][2 * node + 1]);
	}
}
 
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
	cin >> n;
	int pos, st;
	for (int i = 0; i < n; i++) {
		cin >> pos >> st;
		upd(1, 1, n, 1, pos, (st == 1 ? -1 : 1));
		int mn = a[0][1];
		int mx = a[1][1];
		if (mn >= 0 && mx >= 0) cout << "<\n";
		else if (mn <= 0 && mx <= 0) cout << ">\n";
		else cout << "?\n";
	}
    return 0;
}