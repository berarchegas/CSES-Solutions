/*
Problem Name: Increasing Subsequence II
Problem Link: https://cses.fi/problemset/task/1748
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 200100
#define INF 1e18
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int M = 1e9+7;
 
ll a[MAXN], dp[MAXN];
int v[MAXN];
 
void upd(int pos, ll val) { for (; pos < MAXN; pos += (pos & -pos)) a[pos] = (a[pos] + val) % M; }
 
ll sum(int pos) {
	ll ans = 1;
	for (; pos > 0; pos -= (pos & -pos)) {
		ans += a[pos];
		if (ans >= M) ans -= M;
	}
	return ans;
}
 
int main () { _
	int n;
	cin >> n;
	vector<int> w;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		w.pb(v[i]);
	}
	sort(w.begin(), w.end());
	w.erase(unique(w.begin(), w.end()), w.end());
	for (int i = 1; i <= n; i++) {
		v[i] = upper_bound(w.begin(), w.end(), v[i]) - w.begin();
	}
	for (int i = 1; i <= n; i++) {
		dp[i] += sum(v[i]-1);
		dp[i] %= M;
		upd(v[i], dp[i]);
	}
	cout << sum(MAXN-1) - 1 << '\n';
    return 0;
}