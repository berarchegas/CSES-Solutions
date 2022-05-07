/*
Problem Name: Necessary Roads
Problem Link: https://cses.fi/problemset/task/2076
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
vector<pii> edges;
int vis[MAXN], dp[MAXN], dep[MAXN];
 
void dfs(int node, int pai) {
	dep[node] = dep[pai] + 1;
	vis[node] = 1;
	for (int x : v[node]) {
		if (x == pai) continue;
		if (vis[x]) {
			if (dep[node] > dep[x]) dp[node]--;
			else dp[node]++;
		}
		else {
			dfs(x, node);
			dp[node] += dp[x];
		}
	}
	if (!dp[node] && node > 1) edges.emplace_back(node, pai);
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
	dfs(1, -1);
	cout << edges.size() << '\n';
	for (auto x : edges) cout << x.first << ' ' << x.second << '\n';
    return 0;
}