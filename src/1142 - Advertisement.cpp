// Advertisement
//
// Problem name: Advertisement
// Problem Link: https://cses.fi/problemset/task/1142
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

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
 
int v[MAXN];
 
int main () { _
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> v[i];
	v[n+1] = 0;
	vector<pii> sk;
	sk.pb({v[1], 1});
	ll ans = 0;
	for (int i = 2; i <= n+1; i++) {
		while (!sk.empty() && sk.back().F >= v[i]) {
			ans = max(ans, 1ll * (i-1 - ((int)sk.size() == 1 ? 0 : sk[(int)sk.size()-2].S)) * sk.back().F);
			sk.pop_back();
		}
		sk.pb({v[i], i});
	}
	cout << ans << '\n';
    return 0;
}