/*
Problem Name: Graph Paths I
Problem Link: https://cses.fi/problemset/task/1723
Author: Bernardo Archegas (codeforces/profile/Ber)
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
const int M = 1e9 + 7;
 
typedef vector<vector<ll>> matriz;
 
int n;
 
matriz mult(matriz a, matriz b) {
	matriz c(n, vector<ll> (n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				c[i][j] += (a[i][k] * b[k][j]) % M;
				if (c[i][j] >= M) c[i][j] -= M; 
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
	matriz v(n, vector<ll> (n));
	for (int i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		v[a-1][b-1]++;
	}
	v = expo(v, k);
	cout << v[0][n-1] << '\n';
	return 0;
}