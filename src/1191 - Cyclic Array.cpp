// Cyclic Array
//
// Problem name: Cyclic Array
// Problem Link: https://cses.fi/problemset/task/1191
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
    
const int MOD = 1e9 + 7;
const int MAXN = 2e6 + 5;
const ll INF = 2e18;
 
ll v[MAXN], pre[MAXN], to[MAXN], n, b;
 
void solve() {
    int r = 1; 
    for (int l = 1; l <= 2 * n; l++) {
        while (r <= 2 * n && pre[r + 1] - pre[l - 1] <= b) r++;
        to[l] = r;
    }
    int mn = 2 * n + 1, id = -1;
    for (int i = 1; i <= n; i++) {
        if (to[i] - i + 1 < mn) {
            mn = to[i] - i + 1;
            id = i;
        }
    }
    int st = id, ans = 1e9;
    for (int i = id; i <= id + mn; i++) {
        int cur = st, cnt = 0;
        while (cur - st < n) {
            cur = to[cur] + 1;
            cnt++;
        }
        ans = min(ans, cnt);
        st = st % n + 1;
    }
    cout << ans << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> b;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i + n] = v[i];
    }
    for (int i = 1; i <= 2 * n; i++) {
        pre[i] = v[i] + pre[i - 1];
    }
    solve();
    return 0;
}