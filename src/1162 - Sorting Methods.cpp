/*
Problem Name: Sorting Methods
Problem Link: https://cses.fi/problemset/task/1162
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
const ll INF = 1e18;
 
int v[MAXN], a[MAXN], inv[MAXN], vis[MAXN];
vector<int> adj[MAXN];
 
int sum(int pos) {
    int ans = 0;
    for (; pos; pos -= (pos & -pos)) ans += a[pos];
    return ans;
}
 
void upd(int pos, int val) { for (; pos < MAXN; pos += (pos & -pos)) a[pos] += val; }
 
void dfs(int node) {
    vis[node] = 1;
    for (int x : adj[node]) 
        if (!vis[x]) dfs(x);
}
 
int lis(int n) {
    vector<int> pilha;
    for (int i = 0; i < n; i++) {
        auto pos = lower_bound(pilha.begin(), pilha.end(), v[i]);
        if (pos == pilha.end())
            pilha.push_back(v[i]);
        else *pos = v[i];
    }
    return pilha.size();
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i];
    ll ans1 = 0;
    int ans2 = n, ans3 = n, ans4 = n;
    int atual = n;
    for (int i = n-1; i >= 0; i--) {
        ans1 += sum(v[i]);
        upd(v[i], 1);
        if (v[i] == atual) {
            atual--;
            ans4--;
        }
        adj[v[i]].push_back(i+1);
        adj[i+1].push_back(v[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            ans2--;
        }
    }
    ans3 -= lis(n);
    cout << ans1 << ' ' << ans2 << ' ' << ans3 << ' ' << ans4 << '\n';
    return 0;
}