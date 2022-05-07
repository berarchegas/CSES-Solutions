/*
Problem Name: Even Outdegree Edges
Problem Link: https://cses.fi/problemset/task/2179
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
*/
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;
const ll INF = 1e18;
 
vector<int> v[MAXN];
int vis[MAXN], cnt = 0, deg[MAXN], dep[MAXN];
 
void dfs(int node, int pai) {
	dep[node] = dep[pai]+1;
	vis[node] = 1;
	for (int x : v[node]) {
		cnt++;
		if (x == pai) continue;
		if (!vis[x]) 
			dfs(x, node);
	}
}
 
void dfs2(int node, int pai) {
	vis[node] = 1;
	for (int x : v[node]) {
		if (x == pai) continue;
		if (!vis[x]) {
			dfs2(x, node);
			if (deg[x]) 
				cout << x << ' ' << node << '\n';
			else {
				cout << node << ' ' << x << '\n';
				deg[node] ^= 1;
			}
		}
		else if (dep[node] > dep[x]) {
			cout << node << ' ' << x << '\n';
			deg[node] ^= 1;
		}
	}
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
	}
	bool valid = true;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			cnt = 0;
			dfs(i, 0);
			cnt /= 2;
			valid &= (cnt % 2 == 0);
		}
	}
	if (!valid) cout << "IMPOSSIBLE\n";
	else {
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				dfs2(i, 0);
			}
		}
	}
    return 0;
}