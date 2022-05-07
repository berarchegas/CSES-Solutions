/*
Problem Name: Range Updates and Sums
Problem Link: https://cses.fi/problemset/task/1735
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
typedef long long int ll;
typedef pair<int, int> pii;
const int M = 1e9+7;
 
ll v[MAXN], a[4*MAXN], lz1[4*MAXN], lz2[4*MAXN], a1[4*MAXN], a2[4*MAXN];
 
void build(int node, int i, int j) {
	if (i == j) a[node] = v[i];
	else {
		int m = (i+j)/2;
		build(2*node, i, m), build(2*node+1, m+1, j);
		a[node] = a[2*node] + a[2*node+1];
	}
}
 
void push(int node, int i, int j) {
	if (a1[node]) {
		a[node] = (j-i+1) * lz1[node];
		if (i != j) {
			lz1[2*node] = lz1[2*node+1] = lz1[node];
			a1[2*node] = a1[2*node+1] = 1;
			lz2[2*node] = lz2[2*node+1] = a2[2*node] = a2[2*node+1] = 0;
		}
		lz2[node] = lz1[node] = a2[node] = a1[node] = 0;
	}
	if (a2[node]) {
		a[node] += (j-i+1) * lz2[node];
		if (i != j) {
			if (lz1[2*node]) {
				lz1[2*node] += lz2[node];
				lz2[2*node] = 0;
				a2[2*node] = 0;
			}
			else {
				lz2[2*node] += lz2[node];
				a2[2*node] = 1;
			}
			if (lz1[2*node+1]) {
				lz1[2*node+1] += lz2[node];
				lz2[2*node+1] = 0;
				a2[2*node+1] = 0;
			}
			else {
				lz2[2*node+1] += lz2[node];
				a2[2*node+1] = 1;
			}
		}
		lz2[node] = 0;
		a2[node] = 0;
	}
}
 
void upd(int node, int i, int j, int ini, int fim, int val, bool set) {
	push(node, i, j);
	if (j < ini || i > fim) return;
	if (ini <= i && j <= fim) {
		if (set) {
			lz1[node] = val;
			a1[node] = true;
		}
		else {
			if (a1[node]) lz1[node] += val;
			else {
				lz2[node] += val;
				a2[node] = true;
			}
		}
		push(node, i, j);
	}
	else {
		int m = (i+j)/2;
		upd(2*node, i, m, ini, fim, val ,set);
		upd(2*node+1, m+1, j, ini, fim, val, set);
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
	int tipo, a, b, val;
	for (int i = 0; i < q; i++) {
		cin >> tipo >> a >> b;
		if (tipo == 1) {
			cin >> val;
			upd(1, 1, n, a, b, val, false);
		}
		if (tipo == 2) {
			cin >> val;
			upd(1, 1, n, a, b, val, true);
		}
		if (tipo == 3) {
			cout << query(1, 1, n, a, b) << '\n';
		}
	}
    return 0;
}