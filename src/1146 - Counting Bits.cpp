/*
Problem Name: Counting Bits
Problem Link: https://cses.fi/problemset/task/1146
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
	ll n;
	cin >> n;
	ll ans = 0, aux, add, two;
	n++;
	for (int i = 0; i <= 50; i++) {
		two = (1ll<<i);
		aux = n - two;
		if (aux < 0) break;
		add = aux / two;
		if (add&1) add = ((add+1) / 2) * two;
		else add = add * two / 2 + aux % two;
		ans += add;
	}
	cout << ans << '\n';
    return 0;
}