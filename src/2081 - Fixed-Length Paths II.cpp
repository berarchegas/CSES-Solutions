/*
Problem Name: Fixed-Length Paths II
Problem Link: https://cses.fi/problemset/task/2081
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
 
vector<int> v[MAXN];
int sz[MAXN], n, k1, k2, mx;
ll ans, a[MAXN];
bool vis[MAXN];
 
void upd(int pos, int val) {
    for (pos++; pos < MAXN; pos += pos & -pos) a[pos] += val;
}
 
ll query(int l, int r) {
    ll ans = 0;
    for (; l; l -= l & -l) ans -= a[l];
    for (r++; r; r -= r & -r) ans += a[r];
    return ans;
}
 
int subtree(int node, int pai = 0) {
    sz[node] = 1;
    for (int x : v[node]) {
        if (!vis[x] && x != pai) {
            sz[node] += subtree(x, node);
        }
    }
    return sz[node];
}
 
int centroid(int node, int desired, int pai = 0) {
    for (int x : v[node]) {
        if (!vis[x] && x != pai && sz[x] >= desired) {
            return centroid(x, desired, node);
        }
    }
    return node;
}
 
void get_cnt(int node, int pai, bool filling, int depth) {
    if (depth > k2) return;
    mx = max(mx, depth);
    if (filling) {
        upd(depth, 1);
    }
    else {
        ans += query(max(0, k1 - depth), k2 - depth);
    }
    for (int x : v[node]) {
        if (!vis[x] && x != pai) {
            get_cnt(x, node, filling, depth + 1);
        }
    }
}
 
void solve(int node) {
    int c = centroid(node, subtree(node) / 2);
    vis[c] = true;
    mx = 0;
    for (int x : v[c]) {
        if (!vis[x]) {
            get_cnt(x, c, false, 1);
            get_cnt(x, c, true, 1);
        }
    }
    for (int i = 1; i <= mx; i++) upd(i, -query(i, i));
    for (int x : v[c]) {
        if (!vis[x]) {
            solve(x);
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k1 >> k2;
    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    upd(0, 1);
    solve(1);
    cout << ans << '\n';
    return 0;
}