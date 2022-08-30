/*
Problem Name: New Roads Queries
Problem Link: https://cses.fi/problemset/task/2101
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
 
int sz[MAXN], pai[MAXN], te[MAXN];
 
int find(int x) {
    if (x == pai[x]) return x;
    return find(pai[x]);
}
 
void join(int a, int b, int t) {
    a = find(a), b = find(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    pai[b] = a;
    if (sz[a] == sz[b]) sz[a]++;
    te[b] = t;
}
 
int query(int a, int b) {
    int ans = 0;
    if (find(a) != find(b)) return -1;
    while (a != b) {
        if (te[a] > te[b]) {
            ans = te[b];
            b = pai[b];
        }
        else {
            ans = te[a];
            a = pai[a];
        }
    }
    return ans;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q, a, b;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) pai[i] = i, sz[i] = 1, te[i] = m + 1;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        join(a, b, i);
    }
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        cout << query(a, b) << '\n';
    }
    return 0;
}