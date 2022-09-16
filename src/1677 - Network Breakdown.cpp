// Network Breakdown
//
// Problem name: Network Breakdown
// Problem Link: https://cses.fi/problemset/task/1677
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
 
vector<int> v[MAXN];
int pai[MAXN], peso[MAXN], vis[MAXN];
set<pii> inv;
vector<pii> edg;
 
int find(int x) {
	if (pai[x] == x) return x;
	else return pai[x] = find(pai[x]);
}
 
void join(int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return;
	if (peso[a] > peso[b]) 
		pai[b] = a;
	else if (peso[b] > peso[a])
		pai[a] = b;
	else {
		peso[a]++;
		pai[b] = a;
	}
}
 
void dfs(int node, int pai) {
	vis[node] = 1;
	for (int x : v[node]) {
		if (!inv.count({x, node}) && !inv.count({node, x}) && !vis[x]) {
			dfs(x, node);
			join(node, x);
		}
	}
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) pai[i] = i; 
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		inv.insert({a, b});
		edg.emplace_back(a, b);
	}
	vector<int> resp;
	int comps = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			dfs(i, 0);
			comps++;
		}
	}
	resp.push_back(comps);
	for (int i = (int)edg.size()-1; i > 0; i--) {
		if (find(edg[i].first) != find(edg[i].second)) {
			comps--;
			join(edg[i].first, edg[i].second);
		}
		resp.push_back(comps);
	}
	reverse(resp.begin(), resp.end());
	for (int x : resp) cout << x << '\n';
    return 0;
}