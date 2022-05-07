/*
Problem Name: Counting Sequences
Problem Link: https://cses.fi/problemset/task/2228
Author: Bernardo Archegas (https://codeforces.com/profile/Ber)
*/
#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
 
const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;
const ll INF = 2e18;
 
int fat[MAXN], inv[MAXN];
 
int fexp(ll b, int e) {
    ll ans = 1;
    while (e) {
        if (e & 1) ans = (ans * b) % MOD;
        b = (b * b) % MOD;
        e >>= 1;
    }
    return ans;
}
 
void init() {
    fat[0] = 1;
    for (int i = 1; i < MAXN; i++) fat[i] = (1ll * fat[i - 1] * i) % MOD;
    inv[MAXN - 1] = fexp(fat[MAXN - 1], MOD - 2);
    for (int i = MAXN - 2; i >= 0; i--) inv[i] = (1ll * inv[i + 1] * (i + 1)) % MOD;
}
 
int mul(int a, int b) {
    return 1ll * a * b % MOD;
}
 
void add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    if (a < 0) a += MOD;
}
 
int nck(int n, int k) {
    if (k > n || k < 0) return 0;
    return (((1ll * fat[n] * inv[k]) % MOD) * 1ll * inv[n - k]) % MOD;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for (int i = 0; i < k; i++) {
        add(ans, (i % 2 == 0 ? 1 : -1) * mul(fexp(k - i, n), nck(k, k - i)));
    }
    cout << ans << '\n';
    return 0;
}