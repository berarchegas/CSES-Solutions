// Network Renovation
//
// Problem name: Network Renovation
// Problem Link: https://cses.fi/problemset/task/1704
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;
const ll INF = 1e18;
 
vector<int> v[MAXN], fol;
 
void dfs(int node, int pai) {
	for (int x : v[node]) {
		if (x != pai) dfs(x, node);
	}
	if ((int)v[node].size() == 1) fol.push_back(node);
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, 0);
	// cnt eh o numero de filhos da raiz
	int tam = (int)fol.size();
	if (tam&1) fol.push_back(fol[0]), tam++;
	cout << tam/2 << '\n';
	for (int i = 0; i < tam/2; i++) {
		cout << fol[i] << ' ' << fol[i+tam/2] << '\n';
	}
    return 0;
}