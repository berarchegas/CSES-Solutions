/*
Problem Name: Coding Company
Problem Link: https://cses.fi/problemset/task/1165
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
const ll INF = 1e18;
 
int dp1[105][10010], dp2[105][10010], v[105];
 
int add(int a, int b) {
    if (a + b >= MOD)
        return a + b - MOD;
    if (a + b < 0)
        return a + b + MOD;
    return a + b;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> v[i];
    sort(v + 1, v + n + 1);
    // dp1 receives from dp2
    dp2[0][5000] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= 10000; k++) {
                dp1[j][k] = add(dp1[j][k], (1ll * dp2[j][k] * (j+1)) % MOD);
                if (k + v[i] <= 10000 && j) 
                    dp1[j][k] = add(dp1[j][k], dp2[j-1][k + v[i]]);
                if (k - v[i] >= 0)
                    dp1[j][k] = add(dp1[j][k], (1ll * dp2[j+1][k-v[i]] * (j+1)) % MOD);
            }
        }
        for (int j = 0; j <= i; j++) {
            for (int k = 0; k <= 5000 + x; k++) {
                dp2[j][k] = dp1[j][k];
                dp1[j][k] = 0;
            }
        }
    }
    int ans = 0;
    for (int i = 5000; i <= 10000; i++) 
        ans = add(ans, dp2[0][i]);
    cout << ans << '\n';
    return 0;
}