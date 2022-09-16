// Swap Game
//
// Problem name: Swap Game
// Problem Link: https://cses.fi/problemset/task/1670
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

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
const int N = 381367045;
 
bitset<N> vis;
int pwr[10];
 
int h(int atual, int pos) {
	if (pos == 2 || pos == 5) return 0;
	int ini = atual;
	int p0, p1, cnt = 0;
	while (cnt <= pos) {
		if (cnt == pos) p0 = atual % 9;
		atual /= 9;
		cnt++;
	}
	p1 = atual % 9;
	return ini - pwr[pos] * p0 - pwr[pos+1] * p1 + pwr[pos] * p1 + pwr[pos+1] * p0;
}
 
int v(int atual, int pos) {
	if (pos >= 6) return 0;
	int ini = atual;
	int p0, p1, cnt = 0;
	while (cnt <= pos+2) {
		if (cnt == pos) p0 = atual % 9;
		atual /= 9;
		cnt++;
	}
	p1 = atual % 9;
	return ini - pwr[pos] * p0 - pwr[pos+3] * p1 + pwr[pos] * p1 + pwr[pos+3] * p0;
}
 
int main () { _
	pwr[0] = 1;
	for (int i = 1; i < 10; i++) pwr[i] = 9 * pwr[i-1];
	int start = 0, aux, meta = 0;
	for (int i = 0; i < 9; i++) {
		cin >> aux;
		start += pwr[i] * (aux % 9);
		meta += pwr[i] * ((i+1) % 9);
	}
	v(start, 5);
	queue<pii> fila;
	fila.push({start, 0});
	vis[0] = 1;
	vis[start] = 1;
	int ans = -1, hor, ver;
	while (!fila.empty()) {
		pii atual = fila.front();
		fila.pop();
		if (atual.F == meta) {
			ans = atual.S;
			break;
		}
		for (int i = 0; i < 8; i++) {
			hor = h(atual.F, i), ver = v(atual.F, i);
			if (!vis[hor]) {
				vis[hor] = 1;
				fila.push({hor, atual.S+1});
			}
			if (!vis[ver]) {
				vis[ver] = 1;
				fila.push({ver, atual.S+1});
			}
		}
	}
	cout << ans << '\n';
    return 0;
}