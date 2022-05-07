/*
Problem Name: Grid Paths
Problem Link: https://cses.fi/problemset/task/1078
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 100100
#define INF 1000000001
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
const int M = 1e9 + 7;
 
int fexp(ll b, int e) {
	ll resp = 1;
	while (e) {
		if (e&1) resp = (resp * b) % M;
		e = (e>>1);
		b = (b * b) % M;
	}
	return resp;
}
 
int main () { _
	int h, w, n;
	cin >> h >> n;
	w = h;
	vector<ll> inv(1000100, 1), fat(2000100, 1), dp(n);
	ll f;
	for (int i = 2; i < 2000050; i++) {
		f = fat[i-1]*i % M;
		fat[i] = f;
	}
	inv[1000050] = fexp(fat[1000050], M-2);
	for (int i = 1000049; i >= 0; i--) {
		inv[i] = (inv[i+1] * (i+1)) % M;
	}
	vector<pii> v(n);
	for (int i = 0; i < n; i++) cin >> v[i].F >> v[i].S;
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		dp[i] = fat[v[i].F + v[i].S - 2] * inv[v[i].F - 1] % M;
		dp[i] = dp[i] * inv[v[i].S - 1] % M;
		for (int j = i-1; j >= 0; j--) {
			if (v[j].F <= v[i].F && v[j].S <= v[i].S) {
				ll nova = dp[j] * fat[v[i].F - v[j].F + v[i].S - v[j].S] % M;
				nova = nova * inv[v[i].F - v[j].F] % M;
				nova = nova * inv[v[i].S - v[j].S] % M;
				dp[i] -= nova;	
				if (dp[i] < 0) dp[i] += M;
			}
		}
	}
	ll total = fat[h+w-2] * inv[h-1] % M;
	total = total * inv[w-1] % M;
	for (int i = 0; i < n; i++) {
		dp[i] = dp[i] * fat[h + w - v[i].F - v[i].S] % M;
		dp[i] = dp[i] * inv[h - v[i].F] % M;
		dp[i] = dp[i] * inv[w - v[i].S] % M;
		total -= dp[i];
		if (total < 0) total += M;
	}
	cout << total << '\n';
	return 0;
}