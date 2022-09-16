// Polygon Lattice Points
//
// Problem name: Polygon Lattice Points
// Problem Link: https://cses.fi/problemset/task/2193
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
 
int main () { _
	int n;
	cin >> n;
	vector<pll> v(n);
	for (int i = 0; i < n; i++) cin >> v[i].F >> v[i].S;
	ll area = 0, pts = 0;
	for (int i = 0; i < n; i++) {
		pll last = v[(i+1) % n];
		area += (last.F - v[i].F) * (last.S + v[i].S);
		pts += __gcd(abs(last.F - v[i].F), abs(last.S - v[i].S));
	}
	area = abs(area);
	ll ipts = area + 2 - pts;
	cout << ipts/2 << ' ' << pts << '\n';
    return 0;
}