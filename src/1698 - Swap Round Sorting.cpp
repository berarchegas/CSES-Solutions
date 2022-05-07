/*
Problem Name: Swap Round Sorting
Problem Link: https://cses.fi/problemset/task/1698
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
    
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;
const ll INF = 2e18;
 
int v[MAXN], vis[MAXN];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	vector<vector<int>> cic;
	vector<int> sz;
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vector<int> nv;
			vis[i] = 1;
			nv.push_back(i);
			int bg = i, at = v[i];
			while (at != bg) {
				vis[at] = 1;
				nv.push_back(at);
				at = v[at];
			}
			cic.push_back(nv);
			sz.push_back(nv.size());
			mx = max(mx, (int)nv.size());
		}
	}
	memset(vis, 0, sizeof(vis));
	int ans = min(2, (int)ceil(log2(mx)));
	cout << ans << '\n';
	int qtd = 0;
	for (int j = 0; j < (int)cic.size(); j++) {
		qtd += sz[j] / 2;
	}
	cout << qtd << '\n';
	for (int j = 0; j < (int)cic.size(); j++) {
		int tam = cic[j].size();
		if (sz[j] > 1) {
			for (int k = 0; k < tam / 2; k++) {
				cout << cic[j][k] << ' ' << cic[j][tam - k - 1] << '\n'; 
				swap(v[cic[j][k]], v[cic[j][tam - k - 1]]);
			}
		}
	}
	if (ans == 2) {
		qtd = 0;
		for (int i = 1; i <= n; i++) {
			if (v[i] != i) qtd++;
		}
		cout << qtd / 2 << '\n';
		for (int i = 1; i <= n; i++) {
			if (v[i] != i && !vis[i]) {
				cout << i << ' ' << v[i] << '\n';
				vis[i] = vis[v[i]] = 1;
			}
		}
	}
    return 0;
}