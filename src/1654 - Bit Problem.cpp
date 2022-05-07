/*
Problem Name: Bit Problem
Problem Link: https://cses.fi/problemset/task/1654
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1e9 + 7;
const int MAXN = 1<<20;
const ll INF = 2e18;
 
int v[200100], dp1[MAXN], dp2[MAXN], c[MAXN];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		dp1[v[i]]++;
		dp2[v[i]]++;
		c[v[i]] = (v[i] ^ ((1<<20)-1));
	}
	for (int i = 0; i <= 19; i++) {
		for (int j = (1<<20)-1; j >= 0; j--) {
			if (j & (1<<i)) {
				dp1[j] += dp1[j ^ (1<<i)];
			}
		}
		for (int j = 0; j <= 1e6; j++) {
			if (!(j & (1<<i)) && (j ^ (1<<i)) <= 1e6) {
                dp2[j] += dp2[j ^ (1<<i)];
            }
		}
	}
	for (int i = 0; i < n; i++) {
		cout << dp1[v[i]] << ' ' << dp2[v[i]] << ' ' << n - dp1[c[v[i]]] << '\n';
	}
    return 0;
}