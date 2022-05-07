/*
Problem Name: Fibonacci Numbers
Problem Link: https://cses.fi/problemset/task/1722
Author: Bernardo Archegas (codeforces/profile/Ber)
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
 
typedef vector<vector<ll>> matriz;
 
matriz mat;
 
matriz mult(matriz a, matriz b) {
	matriz c(2, vector<ll> (2));
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				c[i][j] = (c[i][j] + (a[i][k] * b[k][j]) % M) % M;
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
	ll n;
	cin >> n;
	if (!n) cout << "0\n";
	else if (n == 1) cout << "1\n";
	else {
		matriz c (2, vector<ll> (2)); 
		c = {{1, 1}, {1, 0}};
		c = expo(c, n-1);
		cout << c[0][0] % M << '\n';
	}
	return 0;
}