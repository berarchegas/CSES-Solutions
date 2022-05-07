/*
Problem Name: Tree Isomorphism I
Problem Link: https://cses.fi/problemset/task/1700
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
int id = 0;
map<vector<int>, int> mp;
 
int dfs(int node, int p, bool at) {
    vector<int> val;
    for (int x : v[at][node]) {
        if (x != p) {
            val.push_back(dfs(x, node, at));
        }
    }
    sort(val.begin(), val.end());
    if (!mp[val]) mp[val] = ++id;
    return mp[val];
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        mp.clear();
        id = 0;
        int n, a, b;
        cin >> n;
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= n; j++) {
                v[i][j].clear();
            }
            for (int j = 0; j < n - 1; j++) {
                cin >> a >> b;
                v[i][a].push_back(b);
                v[i][b].push_back(a);
            }
        }
        int s0 = dfs(1, -1, 0);
        int s1 = dfs(1, -1, 1);
        cout << (s0 == s1 ? "YES\n" : "NO\n");
    }
    return 0;
}