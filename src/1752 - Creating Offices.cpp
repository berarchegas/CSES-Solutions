/*
Problem Name: Creating Offices
Problem Link: https://cses.fi/problemset/task/1752
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
const ll INF = 2e18;
 
vector<int> v[MAXN], ord;
int sz[MAXN], to[20][MAXN], dist[20][MAXN], dep[MAXN], pai[MAXN], ans[MAXN], lvl[MAXN], n, d, tot;
bool vis[MAXN], usei[MAXN];
 
// preprocess
void dfs(int node, int p = 0) {
    if (!p) to[0][node] = node;
    else to[0][node] = p;
    dep[node] = dep[p] + 1;
    for (int x : v[node]) {
        if (x != p) dfs(x, node);
    }
}
void preprocess() {
    dfs(1);
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= n; j++) to[i][j] = to[i - 1][to[i - 1][j]];
    }
}
int lca(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    for (int i = 19; i >= 0; i--) {
        if (dep[a] - (1 << i) >= dep[b]) {
            a = to[i][a];
        }
    }
    if (a == b) return a;
    for (int i = 19; i >= 0; i--) {
        if (to[i][a] != to[i][b]) {
            a = to[i][a];
            b = to[i][b];
        }
    }
    return to[0][a];
}
 
 
// centroid decomposition
int subtree(int node, int p = 0) {
    sz[node] = 1;
    for (int x : v[node]) {
        if (!vis[x] && x != p) {
            sz[node] += subtree(x, node);
        }
    }
    return sz[node];
}
int centroid(int node, int desired, int p = 0) {
    for (int x : v[node]) {
        if (!vis[x] && x != p && sz[x] > desired) {
            return centroid(x, desired, node);
        }
    }
    return node;
}
void dfs1(int node, int p, int l, int d) {
    dist[l][node] = d;
    for (int x : v[node]) {
        if (!vis[x] && x != p) {
            dfs1(x, node, l, d + 1);
        }
    }
}
void solve(int node, int p = 0) {
    int c = centroid(node, subtree(node) / 2);
    vis[c] = true;
    if (p == 0) {
        pai[c] = c;
        lvl[c] = 0;
    } 
    else {
        pai[c] = p;
        lvl[c] = lvl[p] + 1;
    }
    dfs1(c, p, lvl[c], 0);
    for (int x : v[c]) {
        if (!vis[x]) {
            solve(x, c);
        }
    }
}
 
 
// queries
void upd(int node) {
    tot++;
    usei[node] = true;
    int x = node;
    while (true) {
        ans[x] = min(ans[x], dist[lvl[x]][node]);
        if (x == pai[x]) break;
        x = pai[x];
    }
}
int query(int node) {
    int mn = n + 5, x = node;
    while (true) {
        mn = min(mn, ans[x] + dist[lvl[x]][node]);
        if (x == pai[x]) break;
        x = pai[x];
    }
    return mn;
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> d;
    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    preprocess();
    solve(1);
    for (int i = 1; i <= n; i++) {
        ans[i] = 1e9;
        ord.push_back(i);
    }
    sort(ord.begin(), ord.end(), [&] (int a, int b){
        return dep[a] > dep[b];
    }); 
    upd(ord[0]);
    for (int i = 1; i < n; i++) {
        if (query(ord[i]) >= d) {
            upd(ord[i]);
        }
    }
    cout << tot << '\n';
    for (int i = 1; i <= n; i++) {
        if (usei[i]) cout << i << ' ';
    }
    cout << '\n';
    return 0;
}