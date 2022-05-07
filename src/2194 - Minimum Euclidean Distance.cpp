/*
Problem Name: Minimum Euclidean Distance
Problem Link: https://cses.fi/problemset/task/2194
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 2000100
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
 
ll dist(pll a, pll b) {
	return (a.F - b.F) * (a.F - b.F) + (a.S - b.S) * (a.S - b.S);
}
 
int main () { _
	int n;
	cin >> n;
	vector<pll> v(n);
	for (int i = 0; i < n; i++) cin >> v[i].S >> v[i].F;
	sort(v.begin(), v.end(), [&] (pll a, pll b) { return a.S < b.S; });
	ll ans = 9e18;
	ll d = 1e10;
	set<pll> s;
	s.insert(v[0]);
	for (int i = 1; i < n; i++) {
		while (!s.empty() && abs(v[i].S - s.begin()->S) > d)
			s.erase(*s.begin());
		auto it = s.lower_bound({v[i].F - d + 1, v[i].S});
		while (it != s.end() && it->F < v[i].F + d - 1) {
			if (dist(*it, v[i]) < ans) {
				ans = dist(*it, v[i]);
				d = ceil(sqrt(ans));
			}
			it++;
		}
		s.insert(v[i]);
	}
	cout << ans << '\n';
    return 0;
}