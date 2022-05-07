/*
Problem Name: Visiting Cities
Problem Link: https://cses.fi/problemset/task/1203
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
 
vector<pii> v[MAXN];
vector<int> w[MAXN], sla[MAXN];
ll dist[MAXN];
int low[MAXN], nec[MAXN], cnt = 0, vis[MAXN], ja[MAXN], vis15[MAXN], vis2[MAXN];
 
void dfs(int node, int pai) {
	vis[node] = ++cnt;
	low[node] = cnt;
	int filhos = 0;
	for (int x : w[node]) {
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
 
void dfs15(int node) {
    vis15[node] = 1;
    for (int x : sla[node]) {
        if (!vis15[x]) dfs15(x);
    }
}
 
void dfs2(int node) {
    vis2[node] = 1;
    for (auto x : v[node]) {
        if (dist[node] + x.second == dist[x.first]) {
            sla[x.first].push_back(node);
        }
        if (!vis2[x.first]) dfs2(x.first);
    }
}
 
void dijkstra(int n) {
    for (int i = 1; i <= n; i++) dist[i] = INF;
    dist[1] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> fila;
    fila.push({dist[1], 1});
    while (!fila.empty()) {
        pll at = fila.top();
        fila.pop();
        if (dist[at.second] < at.first) continue;
        for (auto x : v[at.second]) {
            if (dist[x.first] > at.first + x.second) {
                dist[x.first] = at.first + x.second;
                fila.push({dist[x.first], x.first});
            }
        }
    }
}
 
void dag(int node) {
    ja[node] = 1;
    for (auto x : v[node]) {
        if (dist[node] + x.second == dist[x.first] && vis15[x.first]) {
            w[x.first].push_back(node);
            w[node].push_back(x.first);
            sla[x.first].push_back(node);
        }
        if (!ja[x.first] && vis15[x.first]) dag(x.first);
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, a, b, c;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        v[a].emplace_back(b, c);
    }
    dijkstra(n);
    dfs2(1);
    dfs15(n);
    dag(1);
    dfs(1, -1);
    nec[1] = nec[n] = 1;
    int qtd = 0;
    for (int i = 1; i <= n; i++) qtd += nec[i];
    cout << qtd << '\n';
    for (int i = 1; i <= n; i++) {
        if (nec[i]) cout << i << ' ';
    }    
    cout << '\n';
    return 0;
}