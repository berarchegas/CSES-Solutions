// Fixed-Length Paths I
//
// Problem name: Fixed-Length Paths I
// Problem Link: https://cses.fi/problemset/task/2080
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

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
int sz[MAXN], cnt[MAXN]{1}, n, k, mx;
ll ans;
bool vis[MAXN];
 
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
        if (!vis[x] && x != pai && sz[x] > desired) {
            return centroid(x, desired, node);
        }
    }
    return node;
}
 
void get_cnt(int node, int pai, bool filling, int depth) {
    if (depth > k) return;
    mx = max(mx, depth);
    if (filling) {
        cnt[depth]++;
    }
    else {
        ans += cnt[k - depth];
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
    fill(cnt + 1, cnt + mx + 1, 0);
    for (int x : v[c]) {
        if (!vis[x]) {
            solve(x);
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    int a, b;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    solve(1);
    cout << ans << '\n';
    return 0;
}