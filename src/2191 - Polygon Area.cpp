/*
Problem Name: Polygon Area
Problem Link: https://cses.fi/problemset/task/2191
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
 
int main () { _
	int n;
	cin >> n;
	vector<pii> v(n);
	for (int i = 0; i < n; i++) cin >> v[i].F >> v[i].S;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		pii last = (!i ? v[n-1] : v[i-1]);
		ans += 1ll * (last.F - v[i].F) * (last.S + v[i].S);
	}
	cout << abs(ans) << '\n';
    return 0;
}