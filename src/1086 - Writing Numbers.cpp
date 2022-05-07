/*
Problem Name: Writing Numbers
Problem Link: https://cses.fi/problemset/task/1086
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
	ll n;
	cin >> n;
	ll ans = 524638270000000001;
	for (int i = 0; i < 10; i++) {
		ll l = 0, r = 524638270000000001;
		while (r > l+1) {
			ll m = (r+l) >> 1, test = m, cnt = 0, pot = 1;
			for (int j = 0; j <= 18; j++) {
				if (!test) break;
				cnt += pot * (test/10 + (test%10 > i));
				if (test%10 == i) cnt += m - test*pot + 1;
				if (!i) cnt -= pot;
				pot *= 10;
				test /= 10;
			}
			if (cnt <= n) l = m;
			else r = m;
		}
		ans = min(ans, l);
	}
	cout << ans << '\n';
    return 0;
}