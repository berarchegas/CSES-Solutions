// Hotel Queries
//
// Problem name: Hotel Queries
// Problem Link: https://cses.fi/problemset/task/1143
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

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
 
int a[4*MAXN], v[MAXN];
 
void build(int node, int ini, int fim) {
	if (ini == fim) {
		a[node] = v[ini];
	}
	else {
		int m = (ini+fim) >> 1;
		build(2*node, ini, m);
		build(2*node+1, m+1, fim);
		a[node] = max(a[2*node], a[2*node+1]);
	}
}
 
int ans(int n, int i, int j, int v) {
	if (i == j && a[n] >= v) {
		int resp = i;
		a[n] -= v;
		return resp;
	}
	else if (i == j) return 0;
	else {
		int m = (i+j) >> 1;
		if (a[2*n] >= v) {
			int resp = ans(2*n, i, m, v);
			a[n] = max(a[2*n], a[2*n+1]);
			return resp;
		}
		else if (a[2*n+1] >= v) {
			int resp = ans(2*n+1, m+1, j, v);
			a[n] = max(a[2*n], a[2*n+1]);
			return resp;
		}
		else {
			return 0;
		}
	}
}
 
int main () { _
	int n, m, aux;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	build(1, 1, n);
	for (int i = 0; i < m; i++) {
		cin >> aux;
		cout << ans(1, 1, n, aux) << ' ';
	}
	cout << '\n';
	return 0;
}