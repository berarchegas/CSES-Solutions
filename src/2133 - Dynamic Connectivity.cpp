/*
Problem Name: Dynamic Connectivity
Problem Link: https://cses.fi/problemset/task/2133
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
*/
#include <bits/stdc++.h>
    
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
    
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
    
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int INF = 2e9;
 
// Seg
 
struct no {
    vector<pii> v;
    no() {
        v = vector<pii> ();
    }
} a[4 * MAXN];
 
void update(int node, int i, int j, int ini, int fim, pii val) {
    if (j < ini || i > fim) return;
    else if (ini <= i && j <= fim) {
        a[node].v.push_back(val);
    }
    else {
        int m = (i + j) / 2;
        update(2 * node, i, m, ini, fim, val);
        update(2 * node + 1, m + 1, j, ini, fim, val);
    }
}
 
int ans[MAXN], pai[MAXN], sz[MAXN], resp;
map<pii, int> mp;
stack<int> st;
 
// DSU
 
int find(int x) {
    if (x == pai[x]) return x;
    return find(pai[x]);
}
 
void join(int a, int b) {
    a = find(a), b = find(b);
    if (sz[a] < sz[b]) {
        swap(a, b);
    }
    pai[b] = a;
    sz[a] += sz[b];
    st.push(b);
    resp--;
}
 
void rollback() {
    int at = st.top();
    st.pop();
    sz[pai[at]] -= sz[at];
    pai[at] = at;
    resp++;
}
 
//
 
void dfs(int node, int i, int j) {
    int cnt = 0;
    for (auto x : a[node].v) {
        if (find(x.first) != find(x.second)) {
            join(x.first, x.second);
            cnt++;
        }
    }
    if (i == j) {
        ans[i] = resp;
    }
    else {
        int m = (i + j) / 2;
        dfs(2 * node, i, m);
        dfs(2 * node + 1, m + 1, j);
    }
    for (int i = 0; i < cnt; i++) {
        rollback();
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k, tipo, a, b;
    cin >> n >> m >> k;
    resp = n;
    for (int i = 1; i <= n; i++) pai[i] = i, sz[i] = 1;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (a > b) swap(a, b);
        mp[{a, b}] = 0;
    }
    for (int i = 1; i <= k; i++) {
        // tempo i
 
        cin >> tipo >> a >> b;
        if (a > b) swap(a, b);
        if (tipo == 1) {
            mp[{a, b}] = i;
        }
        else {
            update(1, 0, k + 1, mp[{a, b}], i - 1, {a, b});
            mp[{a, b}] = -1;
        }
    }
    for (auto x : mp) {
        if (x.second == -1) continue;
        update(1, 0, k + 1, x.second, k + 1, x.first);
    }
    dfs(1, 0, k + 1);
    for (int i = 0; i <= k; i++) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}