/*
Problem Name: Flight Route Requests
Problem Link: https://cses.fi/problemset/task/1699
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
*/
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;
const ll INF = 2e18;
 
vector<int> v[MAXN], w[MAXN], cmp[MAXN];
int at = 0, vis[MAXN];
 
void dfs(int node) {
    vis[node] = 1;
    cmp[at].push_back(node);
    for (int x : w[node]) {
        if (!vis[x]) dfs(x);
    }
}
 
bool dfs2(int node) {
    bool cic = false;
    vis[node] = 1;
    for (int x : v[node]) {
        if (vis[x] == 1) cic = true;
        if (!vis[x]) cic |= dfs2(x);
    }
    vis[node] = 2;
    return cic;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        w[a].push_back(b);
        w[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            at++;
        }
    }
    memset(vis, 0, sizeof(vis));
    int ans = 0;
    for (int i = 0; i < at; i++) {
        bool cic = false;
        for (int x : cmp[i]) {
            if (!vis[x]) cic |= dfs2(x);
        }
        if (cic) ans += cmp[i].size();
        else ans += cmp[i].size() - 1;
    }
    cout << ans << '\n';
    return 0;
}