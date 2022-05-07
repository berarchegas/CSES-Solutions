/*
Problem Name: Convex Hull
Problem Link: https://cses.fi/problemset/task/2195
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
 
ll cross(pll a, pll b, pll c, pll d) {
	return (a.F - b.F) * (c.S - d.S) - (a.S - b.S) * (c.F - d.F);
}
 
void CH(vector<pll> &v) {
	 int n = (int) v.size(), k = 0;
	vector<pll> h(2 * n);
	sort(v.begin(), v.end());
	// lower hull
	for (int i = 0; i < n; i++) {
		while (k >= 2 && cross(h[k - 1], h[k - 2], v[i], h[k - 2]) < 0) k--;
		h[k++] = v[i];
	}
	// upper hull
	for (int i = n - 2, t = k + 1; i >= 0; i--) {
		while (k >= t && cross(h[k - 1], h[k - 2], v[i], h[k - 2]) < 0) {
			k--;
		}
		h[k++] = v[i];
	}
	reverse(h.begin(), h.begin() + k);
	h.resize(k - 1);
	v = h;
}
 
int main () { _
	int n;
	cin >> n;
	vector<pll> v(n);
	for (int i = 0; i < n; i++) cin >> v[i].F >> v[i].S;
	CH(v);
	cout << v.size() << '\n';
	for (auto a : v) cout << a.F << ' ' << a.S << '\n';
    return 0;
}