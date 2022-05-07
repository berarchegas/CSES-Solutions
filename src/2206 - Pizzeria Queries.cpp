/*
Problem Name: Pizzeria Queries
Problem Link: https://cses.fi/problemset/task/2206
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 200100
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
 
int a1[4*MAXN], a0[4*MAXN], v[MAXN], n, q;
 
void build(int node, int i, int j, bool a) {
	if (i == j) {
		if (a) a1[node] = v[i] + i;
		else a0[node] = v[i] + n - i;
	}
	else {
		int m = (i+j)/2;
		build(2*node, i, m, a);
		build(2*node+1, m+1, j, a);
		if (a) a1[node] = min(a1[2*node], a1[2*node+1]);
		else a0[node] = min(a0[2*node], a0[2*node+1]);
	}
}
 
void upd(int node, int i, int j, int pos, bool a) {
	if (i == j) {
		if (a) a1[node] = v[pos] + pos;
		else a0[node] = v[pos] + n - pos;
	}
	else {
		int m = (i+j)/2;
		if (pos <= m) upd(2*node, i, m, pos, a);
		else upd(2*node+1, m+1, j, pos, a);
		if (a) a1[node] = min(a1[2*node], a1[2*node+1]);
		else a0[node] = min(a0[2*node], a0[2*node+1]);
	}
}
 
int ans(int node, int i, int j, int ini, int fim, bool a) {
	if (j < ini || i > fim) return 2e9;
	if (ini <= i && j <= fim) return (a ? a1[node] : a0[node]);
	else {
		int m = (i+j)/2;
		return min(ans(2*node, i, m, ini, fim, a), ans(2*node+1, m+1, j, ini, fim, a));
	}
}
 
int main () { _
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> v[i];
	build(1, 1, n, true);
	build(1, 1, n, false);
	int tipo, x, y;
	for (int i = 0; i < q; i++) {
		cin >> tipo;
		if (tipo == 1) {
			cin >> x >> y;
			v[x] = y;
			upd(1, 1, n, x, 0);
			upd(1, 1, n, x, 1);
		}
		else {
			cin >> x;
			cout << min(ans(1, 1, n, x, n, 1) - x, ans(1, 1, n, 1, x, 0) - n + x) << '\n';
		}
	}
	return 0;
}