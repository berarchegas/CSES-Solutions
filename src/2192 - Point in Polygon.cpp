// Point in Polygon
//
// Problem name: Point in Polygon
// Problem Link: https://cses.fi/problemset/task/2192
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

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
 
ll cross(pll a, pll b, pll c, pll d) {
	ll val = (a.F - b.F) * (c.S - d.S) - (a.S - b.S) * (c.F - d.F);
	if (!val) return 0;
	if (val > 0) return 1;
	else return -1;
}
 
bool mid(pll a, pll b, pll c) {
	return (min(a.F, b.F) <= c.F && max(a.F, b.F) >= c.F && min(a.S, b.S) <= c.S && max(a.S, b.S) >= c.S);
}
 
bool valid(pll a, pll b, pll c, pll d) {
	ll c1, c2, c3, c4;
	c1 = cross(a, b, a, c);
	c2 = cross(a, b, a, d);
	c3 = cross(c, d, c, a);
	c4 = cross(c, d, c, b);
	if (c1 != c2 && c3 != c4) return true;
	if (!c1 && mid(a, b, c)) return true;
	if (!c2 && mid(a, b, d)) return true;
	if (!c3 && mid(c, d, a)) return true;
	if (!c4 && mid(c, d, b)) return true;
	return false;
}
 
int main () { _
	int n, m;
	cin >> n >> m;
	vector<pll> pol(n);
	for (int i = 0; i < n; i++) 
		cin >> pol[i].F >> pol[i].S;
	pll a, aux = {1e9+2, 1e9+1};
	for (int i = 0; i < m; i++) {
		cin >> a.F >> a.S;
		aux = {a.F+1, 1e9+7};
		bool bound = false;
		for (int j = 0; j < n; j++) {
			if (cross(pol[j], (!j ? pol[n-1] : pol[j-1]), pol[j], a) == 0) {
				if (mid(pol[j], (!j ? pol[n-1] : pol[j-1]), a)) bound = true;
			}
		}
		if (bound) cout << "BOUNDARY\n";
		else {
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				cnt += valid(a, aux, pol[j], (!j ? pol[n-1] : pol[j-1]));
			}
			cout << (cnt&1 ? "INSIDE\n" : "OUTSIDE\n");
		}
 
	}
    return 0;
}