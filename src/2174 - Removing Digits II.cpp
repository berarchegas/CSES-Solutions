/*
Problem Name: Removing Digits II
Problem Link: https://cses.fi/problemset/task/2174
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
*/
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
    
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const ll INF = 2e18;
 
// Quantidade de 9s, Maior digito do prefixo, Ultimo digito
ll dp[20][10][10];
int to[20][10][10];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
	// precalc
	for (int j = 0; j < 10; j++) {
		for (int k = 0; k < 10; k++) {
			if (j > k) {
				dp[0][j][k] = 1;
				to[0][j][k] = 10 + k - j; 
			}
			else {
				dp[0][j][k] = 2;
				to[0][j][k] = 10 - j;
			}
		}
	}
    for (int i = 1; i <= 17; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				int lst = k;
				for (int l = 9; l >= 0; l--) {
					dp[i][j][k] += dp[i - 1][max(j, l)][lst];
					lst = to[i - 1][max(j, l)][lst];
				}
				to[i][j][k] = lst;
			}
		}
	}
	
	ll n, ans = 0;
	cin >> n;
	int lst = n % 10, cnt = 0;
	n /= 10;
	while (n % 10 == 9) {
		cnt++;
		n /= 10;
	}
	while (n > 0 || lst > 0 || cnt > 0) {
		int dig = 0;
		ll pre = n;
		while (pre > 0) {
			dig = max(dig, (int)(pre % 10));
			pre /= 10;
		}
		ans += dp[cnt][dig][lst];
		lst = to[cnt][dig][lst];
		if (n == 0) break;
		n--;
		while (n % 10 == 9) {
			cnt++;
			n /= 10;
		}
	}
	cout << ans - 1 << '\n';
    return 0;
}