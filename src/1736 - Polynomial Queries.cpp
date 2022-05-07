/*
Problem Name: Polynomial Queries
Problem Link: https://cses.fi/problemset/task/1736
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 200100
#define INF 100000000
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int M = 998244353;
 
ll v[MAXN], a[4*MAXN];
pll lz[4*MAXN];
 
void build(int node, int i, int j) {
	if (i == j) a[node] = v[i];
	else {
		int m = (i+j)/2;
		build(2*node, i, m), build(2*node+1, m+1, j);
		a[node] = a[2*node] + a[2*node+1];
	}
}
 
void push(int node, int i, int j) {
	a[node] += lz[node].F * 1ll * (j-i+1);
	a[node] += lz[node].S * (1ll * (j-i+1) * (j-i) / 2);
	if (i != j && lz[node].F) {
		int m = (i+j)/2;
		lz[2*node] = {lz[2*node].F + lz[node].F, lz[2*node].S + lz[node].S};
		lz[2*node+1] = {lz[2*node+1].F + lz[node].F + 1ll * (m-i+1) * lz[node].S, lz[2*node+1].S + lz[node].S};
	}
	lz[node] = {0, 0};
}
 
void upd(int node, int i, int j, int ini, int fim) {
	push(node, i, j);
	if (j < ini || i > fim) return;
	if (ini <= i && j <= fim) {
		lz[node].S++;
		lz[node].F += (i-ini+1);
		push(node, i, j);
	}
	else {
		int m = (i+j)/2;
		upd(2*node, i, m, ini, fim);
		upd(2*node+1, m+1, j, ini, fim);
		a[node] = a[2*node] + a[2*node+1];
	}
}
 
ll query(int node, int i, int j, int ini, int fim) {
	push(node, i, j);
	if (j < ini || i > fim) return 0;
	if (ini <= i && j <= fim) return a[node];
	else {
		int m = (i+j)/2;
		return query(2*node, i, m, ini, fim) + query(2*node+1, m+1, j, ini, fim);
	}
}
 
int main () { _
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> v[i];
	build(1, 1, n);
	int tipo, a, b;
	for (int i = 0; i < q; i++) {
		cin >> tipo >> a >> b;
		if (tipo == 1) 
			upd(1, 1, n, a, b);
		if (tipo == 2) 
			cout << query(1, 1, n, a, b) << '\n';
	}
    return 0;
}