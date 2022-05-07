/*
Problem Name: Throwing Dice
Problem Link: https://cses.fi/problemset/task/1096
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 200100
#define INF 1000000001
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
const int M = 1e9+7;
const int x = 6;
 
typedef vector<vector<ll>> matriz;
 
ll n;
 
matriz mult(matriz a, matriz b) {
	matriz c(x, vector<ll> (x));
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			for (int k = 0; k < x; k++) {
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
	cin >> n;
	if (n <= 6) cout << (1<<(n-1)) << '\n';
	else {
		matriz m (6, vector<ll> (6));
		for (int i = 0; i < 6; i++) {
			if (i < 5) m[i][i+1] = 1;
			m[5][i] = 1;
		}
		m = expo(m, n-6);
		ll ans = 0;
		for (int i = 0; i < 6; i++) {
			ans += (m[5][i] * (1<<i)) % M;
			if (ans >= M) ans -= M;
		}
		cout << ans << '\n';
	}
	return 0;
}