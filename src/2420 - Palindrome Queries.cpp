// Palindrome Queries
//
// Problem name: Palindrome Queries
// Problem Link: https://cses.fi/problemset/task/2420
// Author: Bernardo Archegas (https://codeforces.com/profile/Ber)

#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
    
const int MOD = 1e9 + 7;
const int MAXN = 4e5 + 5;
const ll INF = 2e18;
 
int pre[MAXN], pwr[MAXN], a[MAXN];
 
void add(int pos, int val) {
    pos+=2;
    for (; pos < MAXN; pos += (pos & -pos)) {
        a[pos] += val;
        if (a[pos] >= MOD) a[pos] -= MOD;
        if (a[pos] < 0) a[pos] += MOD;
    }
}
 
int ans(int pos) {
    int ans = 0;
    pos+=2;
    for (; pos; pos -= (pos & -pos)) {
        ans += a[pos];
        if (ans >= MOD) ans -= MOD;
        if (ans < 0) ans += MOD;
    }
    return ans;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    string s, ns;
    cin >> n >> m >> s;
    ns = s;
    reverse(ns.begin(), ns.end());
    s += ns;
    pwr[0] = 1;
    for (int i = 1; i < MAXN; i++) pwr[i] = (1ll * pwr[i-1] * 29) % MOD;
    for (int i = 0; i < 2 * n; i++) {
        add(i, ((s[i] - 'a' + 1ll) * pwr[i]) % MOD); 
    }
    int tipo, a, b;
    char c;
    for (int i = 0; i < m; i++) {
        cin >> tipo;
        if (tipo == 1) {
            cin >> a >> c;
            a--;
            add(a, -1 * (((s[a] - 'a' + 1ll) * pwr[a]) % MOD));
            add(2 * n - a - 1, -1 * (((s[2 * n - a - 1] - 'a' + 1ll) * pwr[2 * n - a - 1]) % MOD));
            s[a] = s[2 * n - a - 1] = c;
            add(a, ((s[a] - 'a' + 1ll) * pwr[a]) % MOD);
            add(2 * n - a - 1, ((s[2 * n - a - 1] - 'a' + 1ll) * pwr[2 * n - a - 1]) % MOD);
        }
        else {
            cin >> a >> b;
            a--, b--;
            int val1 = (ans(b) - ans(a - 1) + MOD) % MOD;
            int val2 = (ans(2 * n - a - 1) - ans(2 * n - b - 2) + MOD) % MOD;
            val1 = (1ll * val1 * pwr[2 * n - a - b - 1]) % MOD;
            cout << (val1 == val2 ? "YES\n" : "NO\n");
        }
    }
    return 0;
}