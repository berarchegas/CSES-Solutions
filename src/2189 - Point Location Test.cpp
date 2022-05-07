/*
Problem Name: Point Location Test
Problem Link: https://cses.fi/problemset/task/2189
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
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
	int t;
	cin >> t;
	while (t--) {
		int x1, x2, x3, y1, y2, y3;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		ll val = 1ll * (x2-x1) * (y3-y1) - 1ll * (y2-y1) * (x3-x1);
		if (val == 0) cout << "TOUCH\n";
		if (val < 0) cout << "RIGHT\n";
		if (val > 0) cout << "LEFT\n";
	}
    return 0;
}