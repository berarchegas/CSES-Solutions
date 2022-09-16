// Strongly Connected Edges
//
// Problem name: Strongly Connected Edges
// Problem Link: https://cses.fi/problemset/task/2177
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const ll INF = 1e18;
 
vector<int> v[MAXN];
vector<pii> edges;
int low[MAXN], cnt = 0, vis[MAXN], dep[MAXN];
 
void dfs(int node, int pai) {
	vis[node] = ++cnt;
	low[node] = cnt;
	dep[node] = dep[pai] + 1;
	for (int x : v[node]) {
		if (x == pai) continue;
		if (!vis[x]) {
			dfs(x, node);
			low[node] = min(low[node], low[x]);
		}
		else low[node] = min(low[node], vis[x]);
	}
	if (low[node] == vis[node] && pai > 0) edges.emplace_back(node, pai);
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		edges.emplace_back(a, b);
	}
	int compo = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i, 0);
			compo++;
		}
	}
	if ((int)edges.size() > m || compo > 1) cout << "IMPOSSIBLE\n";
	else {
		for (auto x : edges) {
			if (dep[x.second] > dep[x.first]) swap(x.first, x.second);
			if (dep[x.first] - dep[x.second] == 1) 
				cout << x.second << ' ' << x.first << '\n';
			else 
				cout << x.first << ' ' << x.second << '\n';
		}
	}
    return 0;
}