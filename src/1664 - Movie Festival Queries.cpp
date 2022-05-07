/*
Problem Name: Movie Festival Queries
Problem Link: https://cses.fi/problemset/task/1664
Author: Bernardo Archegas (codeforces/profile/Ber)
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
 
int st[(int) 1e6 + 5], to[20][MAXN];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<pii> v(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i].second >> v[i].first;
    }
    v[n] = {1e6 + 1, 1e6 + 1};
    sort(v.begin(), v.end());
    int at = 0;
    for (int i = 0; i <= n; i++) {
        if (v[i].second >= at) {
            for (int j = at; j <= v[i].second; j++) st[j] = i;
            at = v[i].second + 1;
        }
    }
    for (int i = 0; i <= n; i++) {
        to[0][i] = st[v[i].first];
    }
    for (int i = 1; i < 20; i++) {
        for (int j = 0; j <= n; j++) to[i][j] = to[i - 1][to[i - 1][j]];
    }
    int a, b;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        at = st[a];
        int ans = (v[at].first <= b);
        for (int j = 19; j >= 0; j--) {
            if (v[to[j][at]].first <= b) {
                ans += (1 << j);
                at = to[j][at];
            }
        }
        
        cout << ans << '\n';
    }
    return 0;
}