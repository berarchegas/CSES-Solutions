/*
Problem Name: Multiplication Table
Problem Link: https://cses.fi/problemset/task/2422
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
	ll l = 0, r = n * n;
	while (r > l + 1) {
		ll m = (r + l) / 2;
		ll sum = 0;
		for (int i = 1; i <= n; i++) {
			sum += min(m/i, n);
		}
		if (sum >= (n * n) / 2 + 1) r = m;
		else l = m;
	}
	cout << r << '\n';
    return 0;
}