/*
Problem Name: Tree Isomorphism II
Problem Link: https://cses.fi/problemset/task/1701
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
const ll INF = 2e18;
 
vector<int> v[2][MAXN];
int id = 0, dp[2][MAXN], n;
map<vector<int>, int> mp;
 
int dfs(int node, int p, bool at) {
    dp[at][node] = 1;
    vector<int> val;
    for (int x : v[at][node]) {
        if (x != p) {
            val.push_back(dfs(x, node, at));
            dp[at][node] += dp[at][x];
        }
    }
    sort(val.begin(), val.end());
    if (!mp[val]) mp[val] = ++id;
    return mp[val];
}
 
void dfs2(int node, int p, int at) {
    dp[at][node] = 1;
    for (int x : v[at][node]) {
        if (x != p) {
            dfs2(x, node, at);
            dp[at][node] += dp[at][x];
        }
    }
}
 
vector<int> ctd(int node, int p, bool at) {
    vector<int> ans;
    bool ok = true;
    for (int x : v[at][node]) {
        if (x != p) {
            vector<int> a = ctd(x, node, at);
            for (int x : a) ans.push_back(x);
            ok &= (dp[at][x] <= (n / 2));
        }
    }
    ok &= (n - dp[at][node] <= (n/2));
    if (ok) ans.push_back(node);
    return ans;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        mp.clear();
        id = 0;
        int a, b;
        cin >> n;
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = 0;
                v[i][j].clear();
            }
            for (int j = 0; j < n - 1; j++) {
                cin >> a >> b;
                v[i][a].push_back(b);
                v[i][b].push_back(a);
            }
        }
        dfs2(1, -1, 0), dfs2(1, -1, 1);
        vector<int> c0 = ctd(1, -1, 0), c1 = ctd(1, -1, 1);
        int s0 = dfs(c0[0], -1, 0);
        bool ok = false;
        for (int x : c1) {
            if (dfs(x, -1, 1) == s0) ok = true;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}