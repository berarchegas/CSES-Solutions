/*
Problem Name: Counting Coprime Pairs
Problem Link: https://cses.fi/problemset/task/2417
Author: Bernardo Archegas (codeforces/profile/Ber)
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
 
int main () { _
	ll n, aux;
	cin >> n;
	vector<ll> c(1e6+10), t(1e6+10, -1), p(1e6+10, 1);
	for (int i = 0; i < n; i++) {
		cin >> aux;
		c[aux]++;
	}
	ll ans = (n * (n-1)) / 2;
	ll valid = 0;
	for (int i = 2; i <= 1e6; i++) {
		if (p[i]) {
			t[i] = 1;
			for (int j = 2*i; j <= 1e6; j+=i) {
				p[j] = 0;
				if (j/i % i == 0) t[j] = 0;
				else t[j] = 0 - t[j];
			}
		}
	}
	for (int i = 2; i <= 1e6; i++) {
		if (t[i]) {
			ll total = 0;
			for (int j = i; j <= 1e6; j+=i) total += c[j];
			valid += t[i] * (total * (total-1)) / 2;
		}
	}
	cout << ans - valid << '\n';
    return 0;   
}