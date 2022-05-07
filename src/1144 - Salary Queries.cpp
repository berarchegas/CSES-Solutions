/*
Problem Name: Salary Queries
Problem Link: https://cses.fi/problemset/task/1144
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
*/
#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXN 400100
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
 
vector<int> mapa;
vector<pair<char, pii>> que;
ll a[MAXN], v[MAXN];
 
void upd(int pos, int val) {
	int id = upper_bound(mapa.begin(), mapa.end(), pos) - mapa.begin();
	for (int i = id; i < MAXN; i += (i & -i)) {
		a[i] += val;
	}
}
 
ll sum(int pos) {
	int id = upper_bound(mapa.begin(), mapa.end(), pos) - mapa.begin();
	ll resp = 0;
	for (int i = id; i > 0; i -= (i & -i)) {
		resp += a[i];
	}
	return resp;
}
 
int main () { _
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		mapa.pb(v[i]);
	}
	char c;
	int x, y;
	for (int i = 0; i < q; i++) {
		cin >> c >> x >> y;
		que.pb({c, {x, y}});
		if (c == '!') mapa.pb(y);
	}
	sort(mapa.begin(), mapa.end());
	mapa.erase(unique(mapa.begin(), mapa.end()), mapa.end());
	for (int i = 0; i < n; i++) {
		upd(v[i], 1);
	}
	for (int i = 0; i < q; i++) {
		que[i].S.F--;
		if (que[i].F == '?') {
			cout << sum(que[i].S.S) - sum(que[i].S.F) << '\n';
		}
		else {
			upd(v[que[i].S.F], -1);
			v[que[i].S.F] = que[i].S.S;
			upd(v[que[i].S.F], 1);
		}
	}
	return 0;
}