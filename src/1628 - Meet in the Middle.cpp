/*
Problem Name: Meet in the Middle
Problem Link: https://cses.fi/problemset/task/1628
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 1010
#define INF 1e17
#define pb push_back
#define F first
#define S second
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int M = 998244353;
 
int main () { _
	int n, x, aux;
	cin >> n >> x;
	vector<int> v1, v2;
	for (int i = 0; i < n/2; i++) {
		cin >> aux;
		v1.pb(aux);
	} 
	for (int i = n/2; i < n; i++) {
		cin >> aux;
		v2.pb(aux);
	}
	int tam1 = n/2, tam2 = (n+1)/2, tam;
	vector<ll> resp1(1), resp2(1);
	for (int i = 0; i < tam1; i++) {
		tam = (int)resp1.size();
		for (int j = 0; j < tam; j++) resp1.pb(resp1[j] + v1[i]);
	}
	for (int i = 0; i < tam2; i++) {
		tam = (int)resp2.size();
		for (int j = 0; j < tam; j++) resp2.pb(resp2[j] + v2[i]);
	}
	sort(resp1.begin(), resp1.end());
	sort(resp2.begin(), resp2.end());
	ll ans = 0;
	for (ll a : resp1) {
		if (a > x) break;
		ll look = x-a;
		ans -= lower_bound(resp2.begin(), resp2.end(), look) - upper_bound(resp2.begin(), resp2.end(), look);
	}
	cout << ans << '\n';
	return 0;
}