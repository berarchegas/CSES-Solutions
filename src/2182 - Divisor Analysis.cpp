/*
Problem Name: Divisor Analysis
Problem Link: https://cses.fi/problemset/task/2182
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 1000100
#define INF 100000000
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
const int M = 1e9+7;
 
int fexp(ll b, ll e) {
    ll resp = 1;
    while (e) {
        if (e&1) resp = (resp * b) % M;
        e >>= 1;
        b = (b * b) % M;
    }
    return resp;
}
 
int main () { _
    int n, x, k, pos;
	cin >> n;
	vector<ll> ans(3, 1);
	vector<pii> v;
	bool odd = true;
	ll exp = 1;
	for (int i = 0; i < n; i++) {
		cin >> x >> k;
		v.pb({x, k});
		if (odd && k&1) {
			odd = false;
			pos = i;
		}
		ans[0] = (ans[0] * (k+1)) % M;
		ll prox = ((ll)(fexp(x, k+1) - 1) * fexp(x-1, M-2)) % M;
        ans[1] = (ans[1] * prox) % M;
	}
	for (int i = 0; i < n; i++) {
		if (!odd && pos == i) {
			exp = (exp * (v[i].S+1)/2) % (M-1);
		}
		else exp = (exp * (v[i].S+1)) %  (M-1);
	}
	for (int i = 0; i < n; i++) {
		if (odd) {
			ans[2] = (ans[2] * fexp(v[i].F, (v[i].S/2) * exp)) % M;
		}
		else {
			ans[2] = (ans[2] * fexp(v[i].F, exp * v[i].S)) % M;
		}
	}
	for (int x : ans) cout << x << ' ';
	cout << '\n';
    return 0;   
}