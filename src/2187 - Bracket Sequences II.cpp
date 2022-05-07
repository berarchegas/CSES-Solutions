/*
Problem Name: Bracket Sequences II
Problem Link: https://cses.fi/problemset/task/2187
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 200100
#define INF 100000000
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int M = 1e9 + 7;
 
int main () { _
	int n;
	string s;
	cin >> n >> s;
	int x = 0, y = 0;
	bool valid = true;
	for (int i = 0; i < (int)s.size(); i++) {
		x += (s[i] == '(');
		y += (s[i] == ')');
		valid &= (x >= y);
	}
	vector<ll> fat(2e6+10, 1), inv(1e6+10);
	for (int i = 2; i <= 2e6; i++) {
		fat[i] = (fat[i-1] * i) % M;
	}	
	ll b = fat[1e6], e = M-2, resp = 1;
	while (e) {
		if (e&1) resp = resp * b % M;
		e = (e>>1);
		b = b * b % M;
	}
	inv[1e6] = resp;
	for (int i = 1e6-1; i >= 0; i--) {
		inv[i] = (inv[i+1] * (i+1)) % M;
	}
	if (!valid || x > n/2 || n&1) cout << "0\n";
	else if (x == n/2) cout << "1\n";
	else {
		ll ans = fat[n - x - y] * inv[n/2 - x] % M;
		ans = ans * inv[n/2 - y] % M;
		ll tira = fat[n - x - y] * inv[n/2 - y + 1] % M;
		tira = tira * inv[n/2 - x - 1] % M;
		ans -= tira;
		if (ans < 0) ans += M;
		cout << ans << '\n';
	}
	return 0;
}