/*
Problem Name: Path Queries II
Problem Link: https://cses.fi/problemset/task/2134
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
const int INF = 2e9;
 
vector<int> g[MAXN];
int pos[MAXN], sz[MAXN], pai[MAXN], peso[MAXN];
int h[MAXN], t, n;
int seg[2 * MAXN];
 
void build() {
	for (int i = n - 1; i; i--) seg[i] = max(seg[2*i], seg[2*i+1]);
}
 
int query(int a, int b) {
	int ret = 0;
	for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
		if (a % 2 == 1) ret = max(ret, seg[a]);
		if (b % 2 == 0) ret = max(ret, seg[b]);
	}
	return ret;
}
 
void upd(int p, int x) {
	seg[p += n] = x;
	while (p /= 2) seg[p] = max(seg[2*p], seg[2*p+1]);
}
 
void dfs(int node, int p = -1) {
    sz[node] = 1;
    for (int& x : g[node]) {
        if (x == p) continue;
        dfs(x, node);
        sz[node] += sz[x];
        if (sz[x] > sz[g[node][0]] || g[node][0] == p) swap(x, g[node][0]);
    }
}
 
void build_hld(int k, int p = -1) {
    pos[k] = t++;
    seg[pos[k] + n] = peso[k];
    for (auto& i : g[k]) {
        if (i != p) {
            pai[i] = k;
            h[i] = (i == g[k][0] ? h[k] : i);
            build_hld(i, k); 
        }
    }
}
 
int query_path(int a, int b) {
    if (pos[a] < pos[b]) swap(a, b);
    int ans = 0;
    while (h[a] != h[b]) {
        if (pos[a] < pos[b]) swap(a, b);
        ans = max(ans, query(pos[h[a]], pos[a]));
        a = pai[h[a]];
    }
    if (pos[a] < pos[b]) swap(a, b);
    return max(ans, query(pos[b], pos[a]));
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> peso[i];
    int tipo, a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    h[1] = 1;
    build_hld(1);
    build();
    for (int i = 0; i < q; i++) {
        cin >> tipo >> a >> b;
        if (tipo == 1) {
            upd(pos[a], b);
        }
        else {
            cout << query_path(a, b) << '\n';
        }
    }
    return 0;
}
