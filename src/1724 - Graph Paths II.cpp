/*
Problem Name: Graph Paths II
Problem Link: https://cses.fi/problemset/task/1724
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 200100
#define INF 3e18
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
const ll M = 4294967296;
 
typedef vector<vector<ll>> matriz;
 
int n;
 
matriz mult(matriz a, matriz b) {
	matriz c(n, vector<ll> (n, INF));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				c[i][j] = min(c[i][j], a[i][k] + b[k][j]);
			}
		}
	}
	return c;
}
 
matriz expo(matriz a, ll e) {
	if (e == 1) return a;
	matriz ans = expo(a, e/2);
	ans = mult(ans, ans);
	if (e&1) ans = mult(ans, a);
	return ans;
}
 
int main () { _
	int m, k;
	cin >> n >> m >> k;
	matriz v(n, vector<ll> (n, INF));
	for (int i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		v[a-1][b-1] = min(v[a-1][b-1], c);
	}
	v = expo(v, k);
	if (v[0][n-1] > 1e18) cout << "-1\n";
	else cout << v[0][n-1] << '\n';
	return 0;
}