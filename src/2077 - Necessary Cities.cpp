/*
Problem Name: Necessary Cities
Problem Link: https://cses.fi/problemset/task/2077
Author: Bernardo Archegas (codeforces/profile/Ber)
*/
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
int low[MAXN], nec[MAXN], cnt = 0, vis[MAXN];
 
void dfs(int node, int pai) {
	vis[node] = ++cnt;
	low[node] = cnt;
	int filhos = 0;
	for (int x : v[node]) {
		if (!vis[x]) {
			filhos++;
			dfs(x, node);
			low[node] = min(low[node], low[x]);
		}
		else if (x != pai) low[node] = min(low[node], vis[x]);
	}
	if (node == 1) nec[node] = (filhos > 1);
	else if (low[node] >= vis[pai] && pai > 1) nec[pai] = 1;
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
	vector<int> ans;
	for (int i = 1; i <= n; i++) 
		if (nec[i]) ans.push_back(i);
	cout << ans.size() << '\n';
	for (auto x : ans) cout << x << '\n';
    return 0;
}